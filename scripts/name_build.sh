cd ../.pio/
find ./build -type f ! -name '*.hex' -delete
find ./build -type d -empty -delete
mv build "build_ $(date +%Y%d%m_%H%M)"