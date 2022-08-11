# soundsgood

better sound for live-streaming

![soundsgood on Gnome desktop](/img/soundsgood-gui.png "soundsgood on Gnome desktop")

![DSP signal flow](/img/soundsgood-process.png "DSP signal flow")


## Build for JACK and run

```
$ faust2jack --double-precision-floats soundsgood.dsp
$ ./soundsgood
```
