cd ../.pio/
find ./build -type f ! -name '*.hex' -delete
mv build "build_ $(date +%Y%d%m%H%M)"