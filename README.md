# CoreMediaIO Device Abstraction Layer (DAL) Minimal Example

This example project is intended to present the simplest possible implementation of a CoreMediaIO DAL plugin for creating a virtual webcam on macOS. Apple provides [sample code](https://developer.apple.com/library/archive/samplecode/CoreMediaIO/Introduction/Intro.html) ([also modernized by @lvsti](https://github.com/lvsti/CoreMediaIO-DAL-Example)) but it's extremely painful to read and modify.

The plugin in this repo serves frames as a virtual webcam to host software (QuickTime, OBS, Chrome, etc)

## Donating 💸

If this code is useful to you, feel free to send some cash my way to fund coffee for more late night endeavors like this! I definitely sacrificed sleep several nights to get this thing to work since Apple's docs & sample code are so bad for these APIs. Feel free to [Buy Me a Coffee](https://www.buymeacoffee.com/johnboiles) or [PayPal me](https://paypal.me/johnboiles).

<a href="https://www.buymeacoffee.com/johnboiles" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>

## Other Examples 👀

Other projects that have implemented a DAL plugin:

* [lvsti/CoreMediaIO-DAL-Example](https://github.com/lvsti/CoreMediaIO-DAL-Example) - A direct copy of [Apple's own sample code](https://developer.apple.com/library/archive/samplecode/CoreMediaIO/Introduction/Intro.html).
* [webcamoid/webcamoid](https://github.com/webcamoid/webcamoid) - An example that seems significantly different than the Apple sample code in its implementation.

Projects based on the code in this repo:

* [johnboiles/obs-mac-virtualcam](https://github.com/johnboiles/obs-mac-virtualcam) - This project was my motivation to build this example code. It was originally based on Apple's sample code but is now based on the code in this repo. Creates a virtual camera from the output of Open Broadcaster Software (OBS).
* [Cascable Pro Webcam](https://cascable.se/pro-webcam/) - Very cool piece of software that allows you to use your DSLR as a webcam.

If there are more examples to include here, please share by opening an issue!

## Developing 🛠

To try this out:
* Build it in Xcode
* Find `CMIOMinimalSample.plugin` in Xcode's 'Products' folder
* Right click `CMIOMinimalSample.plugin` and choose 'Show in Finder'
* Copy the plugin bundle to `/Library/CoreMediaIO/Plug-Ins/DAL/`
* Open QuickTime
* Watch the logs in Console.app for any logs prefixed with `CMIOMS`

You may also need to change the codesigning to use your own personal developer identity.

Also take a look at [Cameo](https://github.com/lvsti/Cameo) by @lvsti. It allows you to inspect DAL plugins and see all their properties at a glance. It was very useful to me to take a known-working plugin (like [lvsti/CoreMediaIO-DAL-Example](https://github.com/lvsti/CoreMediaIO-DAL-Example) and [Snap Camera](https://snapcamera.snapchat.com/)) and then use Cameo to understand the differences between those plugins and this plugin.

## Before Shipping Code

Before you bundle this code into your software, you should change the class names to something unique! Objective-C doesn't have namespaces and so if you keep the classes named `Stream`, `Device`, `ObjectStore`, `PlugIn` etc your plugin may not work if you use it along with someone else's plugin who also didn't change the names. This can cause [real bugs](https://github.com/johnboiles/obs-mac-virtualcam/issues/232) where your plugin won't work if someone else's plugin is installed. Typically in Objective-C you add a few letters to the front of your classes to make them unique (e.g. `JBStream`, `JBDevice`, `JBObjectStore`, `JBPlugin`).

You must also change the plugin UUID to something unique in the Info.plist. The sample uses `D8DA9F6A-6723-4497-BC2D-8ADB5F85BC11` which must be changed to a new UUID of your choosing, in both  "Plug-in factory interfaces" and  "Plug-in types" entries.

## License ⚖️

This software is licensed as MIT. Do what you want with it! But please, if you find ways to improve this software, or you find bugs, please open a [Pull Request](https://github.com/johnboiles/coremediaio-dal-minimal-example/pulls) so others can benefit from it! Also I'd love to see what you built with it, so please open an issue or hit me up on [Twitter](https://twitter.com/johnboiles) and show me what you've made!
