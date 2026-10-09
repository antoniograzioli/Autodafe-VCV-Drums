# Autodafe Drum Kit for VCV Rack

A free collection of sample-based drum modules for **VCV Rack**, featuring sounds from classic and vintage drum machines.

The Drum Kit includes **8 dedicated drum modules** plus an **8-channel Drum Mixer**.

## Modules

- **Kick**
- **Snare**
- **Closed Hi-Hats**
- **Open Hi-Hats**
- **Claps**
- **Cymbals**
- **Ride**
- **Rim / Claves**
- **8-Channel Drum Mixer**

Each drum module contains a selection of different vintage drum machine samples that can be selected directly from the front panel.

## Drum Machine Samples

The collection includes sounds inspired by and sampled from classic hardware drum machines such as:

- Roland TR-808
- Roland TR-909
- Roland CR-78
- Korg MiniPops
- LinnDrum
- Alesis HR-16
- E-MU SP-12
- Oberheim DMX

The original samples were collected from freely available sample resources.

## Sample-Rate Independent Playback

The embedded drum samples are stored as 16-bit PCM audio.

Playback has been updated so that samples retain their original **pitch and duration regardless of the VCV Rack engine sample rate**.

The sample player uses:

- 44.1 kHz source sample rate
- fractional sample positions
- linear interpolation
- correct 16-bit little-endian PCM decoding
- proper 16-bit amplitude normalization

This means the drum sounds remain consistent when Rack is running at:

- 44.1 kHz
- 48 kHz
- 88.2 kHz
- 96 kHz

and other engine sample rates.

## Drum Mixer

The included **8-Channel Drum Mixer** is designed to combine the individual drum modules into a complete drum setup.

Each channel provides:

- Audio input
- Individual level control
- Pan control
- CV control for volume and pan
- Mute

The mixer also provides stereo left/right outputs and overall mix level control.

## Installation

The recommended way to install the Drum Kit is through the official **VCV Rack Library**.

Search for:

**Autodafe Drum Kit**

inside Rack's Library.

The modules are available for **VCV Rack 2**.

## Manual Installation

If you build the plugin yourself, run:

```bash
make
make dist
```

This creates a `.vcvplugin` package that can be installed in the appropriate VCV Rack plugin directory.

## Building from Source

Clone the repository and point `RACK_DIR` to your Rack source tree or Rack SDK.

Example:

```bash
export RACK_DIR=/path/to/Rack
make
```

To create the distributable package:

```bash
make dist
```

## Source Code

GitHub repository:

https://github.com/antoniograzioli/Autodafe-VCV-Drums

## More Information

Autodafe website:

https://www.autodafe.net/autodafe-drum-kit-for-vcv-rack.html

VCV Rack modules by Autodafe:

https://www.autodafe.net/virtual-instruments/vcv-rack-modules.html

## Support Autodafe

If you enjoy these modules and would like to support future development:

https://www.paypal.me/autodafe

## License

See the included license files for licensing information.

