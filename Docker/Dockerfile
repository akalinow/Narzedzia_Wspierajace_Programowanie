# Use the official centos image as parent image
FROM ollama/ollama

# Define who is responsible for this Dockerfile
LABEL maintainer="Artur.Kalinowski@fuw.edu.pl"

USER root
RUN apt update
RUN apt -y install \
	python3 python3-pip 

# Install python packages
RUN pip3 install ollama
RUN pip3 install --upgrade jupyter jupyterlab

# Install Jupyter start script
RUN mkdir /opt/jupyter
COPY start-jupyter.sh /opt/jupyter/

