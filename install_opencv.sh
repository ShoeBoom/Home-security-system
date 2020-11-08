cd /tmp/
wget https://github.com/opencv/opencv/archive/4.5.0.tar.gz
tar -xf 4.5.0.tar.gz
cd ./opencv-4.5.0
mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j7
sudo make install