# ==========================
# Makefile for Travel Planner
# ==========================

# Compiler & flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Files
SRC = main.cpp
HEADERS = fileoperations.h location.h route.h graphfunctions.h parser.h
OUT = travel

# Paths
DOCS = ../docs
WEB_STATIC = ../web/static

# ==========================
# Targets
# ==========================

# Default target: build everything
all: build

# Compile C++ backend
build:
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC) $(HEADERS)
	@echo "✅ Backend compiled successfully."

# Run backend binary (CLI testing)
run-backend:
	./$(OUT) $(DOCS)/cities.csv $(DOCS)/routes.csv $(WEB_STATIC)/output.html "Paris" "Berlin" fastest

# Run Flask frontend (auto-build backend first)
run-frontend: build
	cd ../web && python app.py

# Clean compiled files
clean:
	rm -f $(OUT)
	@echo "🧹 Cleaned up compiled binaries."

# Phony targets to avoid filename conflicts
.PHONY: all build run-backend run-frontend clean
