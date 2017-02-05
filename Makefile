.PHONY: clean All

All:
	@echo "----------Building project:[ Bag - Debug ]----------"
	@cd "Bag" && "$(MAKE)" -f  "Bag.mk"
clean:
	@echo "----------Cleaning project:[ Bag - Debug ]----------"
	@cd "Bag" && "$(MAKE)" -f  "Bag.mk" clean
