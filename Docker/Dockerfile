# Use the official centos image as parent image
FROM ubuntu:latest

# Define who is responsible for this Dockerfile
LABEL maintainer="Artur.Kalinowski@fuw.edu.pl"

USER root
RUN apt-get update
RUN apt -y install --fix-missing \
	python3 python3-pip \
	python3-numpy python3-venv \
	wget curl git patchelf\
	nano mc bc rsync htop\
	gzip pigz \
	make cmake 
	#systemd

# Create a virtual environment
RUN python3 -m venv /opt/venv

# Activate the virtual environment
RUN /opt/venv/bin/python3 -m pip install --upgrade pip	

# Install software tools
RUN /opt/venv/bin/python3 -m pip install jupyter jupyterlab matplotlib scipy pandas
RUN /opt/venv/bin/python3 -m pip install ollama

# Install Jupyter start script
RUN mkdir /opt/jupyter
COPY start-jupyter.sh /opt/jupyter/

# Test the installation
RUN mkdir /opt/scripts
COPY test_packages.py /opt/scripts
RUN /opt/venv/bin/python3 /opt/scripts/test_packages.py

