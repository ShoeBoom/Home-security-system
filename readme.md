## Setup
### cmake
make sure cmake version is >=3.16
```shell script
cmake --version
```
if not follow: https://snapcraft.io/install/cmake/debian#install

### curl
```
sudo apt update && sudo apt upgrade
sudo apt install curl
sudo apt-get install libcurl4-openssl-dev
```
### OpenCV
if OpenCV is not installed run the following in the project directory.
```shell script
bash ./install_opencv.sh 
```

## Build & run
```shell script
# Build
mkdir build
cd build
cmake ..
make
# Run
./cs3307
```
