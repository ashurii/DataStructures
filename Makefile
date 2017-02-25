.PHONY: clean All

All:
	@echo "----------Building project:[ dynamic_poly - Debug ]----------"
	@cd "dynamic_poly" && "$(MAKE)" -f  "dynamic_poly.mk"
clean:
	@echo "----------Cleaning project:[ dynamic_poly - Debug ]----------"
	@cd "dynamic_poly" && "$(MAKE)" -f  "dynamic_poly.mk" clean
