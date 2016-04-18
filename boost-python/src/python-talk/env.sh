TALK_DIR="/home/eugen/Documents/Talks/C++\ User\ Group\ Hamburg/boost-python"
export CFLAGS="-I$TALK_DIR/include -Wl,-rpath=$TALK_DIR/lib"
export LDFLAGS="-L$TALK_DIR/lib"
export LD_LIBRARY_PATH="$TALK_DIR/lib:$LD_LIBRARY_PATH"
