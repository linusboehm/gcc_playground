IMAGE_NAME='my-gcc-app'
THIS_DIR="${PWD}"
mkdir -p build; cd build

docker run -it --rm \
    --name my-running-app \
    --volume $THIS_DIR:/usr/src/myapp \
    "${IMAGE_NAME}" $@
