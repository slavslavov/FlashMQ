# FlashMQ

![building](https://github.com/halfgaar/FlashMQ/actions/workflows/building.yml/badge.svg)
![testing](https://github.com/halfgaar/FlashMQ/actions/workflows/testing.yml/badge.svg)
![linting](https://github.com/halfgaar/FlashMQ/actions/workflows/linting.yml/badge.svg)
![docker](https://github.com/halfgaar/FlashMQ/actions/workflows/docker.yml/badge.svg)

FlashMQ is a high-performance, light-weight MQTT broker/server, designed to take good advantage of multi-CPU environments.

Builds (AppImage and a Debian/Ubuntu apt server) are provided on [www.flashmq.org](https://www.flashmq.org).

Building from source can be done with `build.sh`. It's best to checkout a tagged release first. See `git tag`.

## Docker

Official Docker images aren't available yet, but building your own Docker image can be done with the provided Dockerfile.

```
# It's best to checkout a tagged release. See 'git tag'.
git checkout <tag name>

# build flashmq docker image
docker build . -t halfgaar/flashmq

# run using docker (with, as an example, a place for a config file (default
# name flashmq.conf). Create extra volumes as you need, for the persistence DB
# file, logs, password files, auth plugin, etc.
docker run -p 1883:1883 -v /srv/flashmq/etc/:/etc/flashmq halfgaar/flashmq

# for development you can target the build stage to get an image you can use for development
docker build . --target=build
```

See [www.flashmq.org](https://www.flashmq.org)
