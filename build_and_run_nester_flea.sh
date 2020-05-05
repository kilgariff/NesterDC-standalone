#!/bin/bash

BASE=/home/ross/Desktop/flea-toolchain
DIST_PATH=$BASE/flea-files
DREAMCAST_TOOLCHAIN_PATH=$BASE/dc-toolchain
REDREAM_BINARY=$BASE/redream/redream
FIRST_READ_FILE=$DIST_PATH/cd/1ST_READ.BIN
UNSCRAMBLED_BINARY=$DIST_PATH/nester.bin
DCTOOL_IP=/run/media/ross/dreamcast-dev/dcload-ip/dc-tool-ip
CDI4DC_PATH=$BASE/img4dc/build/cdi4dc/cdi4dc

REMOTE_NESTER_PATH=/home/ross/Desktop/NesterDC
REMOTE_DC_TOOLCHAIN_PATH=/home/ross/dreamcast

function fail
{
    echo "Error buiding and running nester flea"
    exit 1
}

# Copy local toolchain to build server.
rsync -avPI $DREAMCAST_TOOLCHAIN_PATH/* ross@192.168.0.70:$REMOTE_DC_TOOLCHAIN_PATH || fail

# Copy local source code to build server.
rsync -avPI ./ ross@192.168.0.70:$REMOTE_NESTER_PATH || fail

# Run the KallistiOS build.
ssh -t ross@192.168.0.70 "cd $REMOTE_NESTER_PATH/kos-1.1.8 && source ./environ-dc.sh && make clean && make" || fail

# Run the NesterDC build.
ssh -t ross@192.168.0.70 "cd $REMOTE_NESTER_PATH && ./dcmake clean && ./dcmake && ./dcmake 1ST_READ.BIN" || fail

# Copy the most recent build from VM.
rm -f "$FIRST_READ_FILE"
rm -f "$UNSCRAMBLED_BINARY"
rsync -avPI ross@192.168.0.70:$REMOTE_NESTER_PATH/obj/1ST_READ.BIN $FIRST_READ_FILE || fail
rsync -avPI ross@192.168.0.70:$REMOTE_NESTER_PATH/obj/nester.bin $UNSCRAMBLED_BINARY || fail

# Remove previous ISO & CDI files.
rm -f "$DIST_PATH/flea.iso"
rm -f "$DIST_PATH/flea.cdi"

if [ -f "$FIRST_READ_FILE" ]; then

    # Generate an ISO file.
    mkisofs -V flea -G $DIST_PATH/IP.BIN -l -r -o $DIST_PATH/flea.iso $DIST_PATH/cd

    # Send ISO file over network to dreamcast.
    #$DCTOOL_IP -i "$DIST_PATH/flea.iso" -x $UNSCRAMBLED_BINARY

    # Convert ISO into a data/data CDI file.
    $CDI4DC_PATH $DIST_PATH/flea.iso $DIST_PATH/flea.cdi -d

    # Run with redream.
    $REDREAM_BINARY $DIST_PATH/flea.cdi

    # Burn to CD.
    # burncdi -c /dev/cdrom $DIST_PATH/flea.cdi
fi