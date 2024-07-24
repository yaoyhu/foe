PROJECT_DIR := $(shell pwd)/../foe
DOCKER_IMAGE := dockerproxy.cn/gcc:12.4
CONTAINER_DIR := /mnt

all: run

# 运行Docker容器并自动进入/mnt
run:
	docker run -it --rm -v $(PROJECT_DIR):$(CONTAINER_DIR) $(DOCKER_IMAGE) /bin/bash -c "cd $(CONTAINER_DIR) && exec /bin/bash"

.PHONY: all run
