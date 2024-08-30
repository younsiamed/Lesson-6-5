# Use Ubuntu 16.04 as the base image
FROM ubuntu:16.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    clang \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /usr/src/app

# Copy the current directory contents into the container
COPY . .

# Compile the project
RUN clang++ -std=c++14 -o testShapes main.cpp

# Run the executable
CMD ["./testShapes"]
