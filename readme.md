## Setup
### cmake
make sure cmake version is >=3.16
```shell script
cmake --version
```
if not follow: https://snapcraft.io/install/cmake/debian#install

### curl
```
sudo apt update && sudo apt upgrade -y
sudo apt install -y curl
sudo apt-get install -y libcurl4-openssl-dev
```
### GTK
```shell script
sudo apt-get install libgtk2.0-dev libgtk-3-dev pkg-config
```

### QT
```shell script
sudo apt-get install qt5-default
```

### OpenCV
if OpenCV is not installed run the following in the project directory.
```shell script
bash ./install_opencv.sh 
```

## Build & run
test for facial recognition
```shell script
# Build
mkdir build
cd build
cmake ..
make
# Run
./cs3307
```
