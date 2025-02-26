# Narzędzia Wspierające Programowanie
Materials for [lecture](https://usosweb.fuw.edu.pl/kontroler.php?_action=katalog2%2Fprzedmioty%2FpokazPrzedmiot&kod=1100-NWP&lang=en) on computing tools at Faculty of Physics, University of Warsaw

## Installation instructions:

```Shell
git clone https://github.com/akalinow/Narzedzia_Wspierajace_Programowanie.git
```

## Update instructions
```Shell
cd Narzedzia_Wspierajace_Programowanie
git commit -a # <--- this will save all the modification made 
              #      to files tracked by the repository (optional)
git stash     # <--- this will remove all modification to files 
              #      tracked in the repository (optional)
git pull      # <--  this download the latest version of the repository    
              #      from the github. I yoy made a commit a conflicts between
              #      your modifications and newer version fom github might occur
```

## Environment setup 

### On pd0XX computers

```Shell
ssh pd0XX                        # Assume ssh configuration for given node is 
                                 # present.Jupyter opens at port 9000. 
                                 # Remember Adjust ssh config.
~akalinow/Publiczny/NWP/nwp_lecture.sif #Start the container
source /opt/venv/bin/activate           #Setup Python virtual environment
/opt/jupyter/start-jupyter.sh    #Start Jupyter server
```

### On private computer with Docker command line
```Shell
sudo docker run --name nwp_lecture --rm -e DISPLAY=$DISPLAY  -v /home/$USER:/scratch -v /tmp/.X11-unix:/tmp/.X11-unix:ro  -w /home/ubuntu -p 9000:9000 akalinow/nwp_lecture 
source /opt/venv/bin/activate    #Setup Python virtual environment
/opt/jupyter/start-jupyter.sh    #Start Jupyter server
```

```Shell
mkdir %USERPROFILE%\Docker
set WORKING_DIR=%USERPROFILE%\Docker
docker pull akalinow/nwp_lecture
docker run --name nwp_lecture -v %WORKING_DIR%:/scratch -w /home/ubuntu -p 9000:9000 akalinow/ml_lecture
source /opt/venv/bin/activate           #Setup Python virtual environment
/opt/jupyter/start-jupyter.sh    #Start Jupyter server
```