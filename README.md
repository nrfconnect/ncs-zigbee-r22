# Zigbee R22 add-on for nRF Connect SDK (Experimental support)

> This is a production ready release of Zigbee R22 support for Nordic Semiconductor’s nRF52833, nRF52840 and nRF5340 SoCs.

The Zigbee R22 add-on for the nRF Connect SDK provides support for developing Zigbee applications based on the third-party precompiled ZBOSS stack. This stack is included as the ZBOSS Zigbee R22 stack library. In combination with the nRF Connect SDK, the Zigbee R22 add-on allows for development of low-power connected solutions.

## Getting started
To get started with Zigbee add-on for nRF Connect SDK, follow [documentation](https://nrfconnect.github.io/ncs-zigbee-r22/).

## Documentation
Pre-build documentation is available [here](https://nrfconnect.github.io/ncs-zigbee-r22).

A minimal documentation setup is provided for Sphinx. To build the
documentation first change to the ``docs`` folder:

```shell
cd docs
```
To install Sphinx, make sure you have a Python installation in place and run:

```shell
pip install -r requirements.txt
```

The Sphinx documentation (HTML) can be built using the following command:

```shell
make html
```

The output will be stored in the ``_build_sphinx`` folder. You may check for
other output formats other than HTML by running ``make help``.


##  License
* Source code included within this repository is licensed under the [LicenseRef-Nordic-5-Clause](https://github.com/nrfconnect/ncs-zigbee/blob/main/LICENSE)
* Pre-compiled ZBOSS libraries (`lib/zboss`) included within this repository are licensed under the [DSR Corporation License](https://github.com/nrfconnect/ncs-zigbee/blob/main/lib/zboss/license.txt)
