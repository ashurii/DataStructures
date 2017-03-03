.PHONY: clean All

All:
	@echo "----------Building project:[ LinkedList - Debug ]----------"
	@cd "Chapter 4 and 5\LinkedList" && "$(MAKE)" -f  "LinkedList.mk"
clean:
	@echo "----------Cleaning project:[ LinkedList - Debug ]----------"
	@cd "Chapter 4 and 5\LinkedList" && "$(MAKE)" -f  "LinkedList.mk" clean
