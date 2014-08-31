#uva-solutions

## uva statistics
http://uhunt.felix-halim.net/id/593482 <br>

##requirements
gcc-c++ >=4.7 <br>
CMake >= 3.0 <br>

##compile
cd uva-solutions <br>
mkdir build && cmake .. && make <br>

##run solution w/ input
cd uva-solutions/build/ <br> 
for problem set volume --> Let psv= vol_xx_xxxx_xxxx <br>
for contest set volume --> Let csv= vol_xxx_xxxxx_xxxxx <br>
replace $(var)=(psv or csv) with actual corresponding directory<br>
./\<filename> < ../sample_input/$(var)/\<filename.cpp> <br>

