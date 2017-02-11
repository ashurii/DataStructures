.PHONY: clean All

All:
	@echo "----------Building project:[ poly - Debug ]----------"
	@cd "poly" && "$(MAKE)" -f  "poly.mk"
clean:
	@echo "----------Cleaning project:[ poly - Debug ]----------"
	@cd "poly" && "$(MAKE)" -f  "poly.mk" clean
