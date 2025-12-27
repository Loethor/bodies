# Smart Makefile for CMake projects
# Usage: just run `make` from the project root

BUILD_DIR := build

.PHONY: all
all:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake ..
	@cd $(BUILD_DIR) && $(MAKE)

.PHONY: run
run: all
	@$(BUILD_DIR)/app

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
