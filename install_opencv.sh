cd /tmp/
git clone https://github.com/opencv/opencv.git
cd ~/opencv
mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j7
sudo make install