cd ../.pio/
find ./build -type f ! -name '*.hex' -type f ! -name '*.bin' -delete
find ./build -type d -empty -delete
mv build "build_ $(date +%Y%m%d_%H%M)"