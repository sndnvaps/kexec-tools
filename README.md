cross compile for arm or arm64 device

1. Install arm-linux-gnueabi-gcc (i have test with gcc5) toolchain from the software center by apt-get or dnf what you like

2. Install libz for arm-linux-gnueabi-gcc toolchain (need to use cross compile)

3. Configure the kexectools

    ```bash
    root@sndnvaps-PC:/home/sndnvaps/kexec-tools# mkdir build_install
    root@sndnvaps-PC:/home/sndnvaps/kexec-tools# CC=arm-linux-gnueabi-gcc-5 LDFLAGS="-static" CFLAGS="-I${PWD}/include -I${PWD}/util_lib/include -I${PWD}/kexec/arch/arm/include -I${PWD}/kexec/libfdt -I${PWD}/purgatory/include" LIBS="-lc" ./configure --host=arm-unknown-linux-gnueabi --prefix=/home/sndnvaps/kexec-tools/build_install

    root@sndnvaps-PC:/home/sndnvaps/kexec-tools# make
    root@sndnvaps-PC:/home/sndnvaps/kexec-tools# make install
    ```
 4. you will got what you want in build_install/sbin   
