.PHONY: clean All

All:
	@echo "----------Building project:[ Multiset - Debug ]----------"
	@cd "Multiset" && "$(MAKE)" -f  "Multiset.mk"
clean:
	@echo "----------Cleaning project:[ Multiset - Debug ]----------"
	@cd "Multiset" && "$(MAKE)" -f  "Multiset.mk" clean
