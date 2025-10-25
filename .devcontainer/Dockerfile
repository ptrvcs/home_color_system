FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
    libx11-xcb1 \
    libxcb-cursor0 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-randr0 \
    libxcb-render-util0 \
    libxcb-shape0 \
    libxcb-shm0 \
    libxcb-sync1 \
    libxcb-xfixes0 \
    libxcb-xinerama0 \
    libxcb-xkb1 \
    libxkbcommon-x11-0 \
    libdbus-1-3 \
    libglib2.0-0 \
    libfontconfig1 \
    libfreetype6 \
    libxext6 \
    libxrender1 \
    libx11-6 \
    libxcb1 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
    libegl1 \
    libgl1 \
    libglx0 \
    libglvnd0 \
    libopengl0 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
    libpcsclite1 \
    libpcsclite-dev \
    libpulse0 \
    libpulse-dev \
    libpipewire-0.3-0 \
    libpipewire-0.3-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
