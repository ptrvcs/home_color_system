FROM mcr.microsoft.com/devcontainers/base:jammy

RUN apt-get update && apt-get install -y \
    git \
    curl \
    python3 \
    python3-pip \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

CMD ["bash"]