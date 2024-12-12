# nwp_lecture

Files used for creation of the Docker image with tools used during the lecture.
Note that is it assumed the local user name is the same as Docker hub user name.

## Creation of image
```bash
sudo docker image build -t candidate  ./ -f Dockerfile 
sudo docker image tag candidate $USER/nwp_lecture
sudo docker image push akalinow/nwp_lecture
```

## Creation of a sif file for apptainer from an existing image.
```bash
apptainer build ollama.sif docker://ollama/ollama
apptainer build ollama_with_jupyter.sif docker://akalinow/nwp_lecture
apptainer push -U ollama.sif library://akalinows/public/ollama:latest
```