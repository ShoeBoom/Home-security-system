## Setup
### cmake
make sure cmake version is >=3.16
```shell script
cmake --version
```
if not follow: https://snapcraft.io/install/cmake/debian#install

### OpenCV
if OpenCV is not installed run the following in the project directory.
```shell script
./install_opencv.sh 
```

## Build & run
```shell script
# Build
mkdr build
cd build
cmake ..
make
# Run
./cs3307
```
