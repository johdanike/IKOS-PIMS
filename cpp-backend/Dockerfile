FROM ubuntu:22.04
# 1. Install required build tools
RUN apt-get update && apt-get install -y cmake build-essential git curl zip unzip tar pkg-config python3 bison flex libpqxx-dev libpq-dev
# 2. Clone and bootstrap vcpkg (Optimized for network stability)
WORKDIR /opt
RUN git config --global http.postBuffer 524288000 && \
    git config --global http.version HTTP/1.1 && \
    git clone --depth 1 https://github.com/microsoft/vcpkg.git
RUN ./vcpkg/bootstrap-vcpkg.sh

# 3. Copy your project code
WORKDIR /app
COPY . .

# 4. Build the project using the vcpkg toolchain so it finds oatpp
RUN mkdir build && cd build && \
    cmake -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake .. && \
    make

# 5. Run the executable
ENTRYPOINT ["./build/pims-cpp"]