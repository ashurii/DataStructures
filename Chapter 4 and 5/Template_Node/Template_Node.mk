##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Template_Node
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/Ashly Altman/Documents/GitHub/DataStructures/Chapter 4 and 5"
ProjectPath            :="C:/Users/Ashly Altman/Documents/GitHub/DataStructures/Chapter 4 and 5/Template_Node"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ashly Altman
Date                   :=17/03/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Template_Node.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/template_node.cpp$(ObjectSuffix) $(IntermediateDirectory)/node_iterator.cpp$(ObjectSuffix) $(IntermediateDirectory)/bag.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ashly Altman/Documents/GitHub/DataStructures/Chapter 4 and 5/Template_Node/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/template_node.cpp$(ObjectSuffix): template_node.cpp $(IntermediateDirectory)/template_node.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ashly Altman/Documents/GitHub/DataStructures/Chapter 4 and 5/Template_Node/template_node.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/template_node.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/template_node.cpp$(DependSuffix): template_node.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/template_node.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/template_node.cpp$(DependSuffix) -MM template_node.cpp

$(IntermediateDirectory)/template_node.cpp$(PreprocessSuffix): template_node.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/template_node.cpp$(PreprocessSuffix) template_node.cpp

$(IntermediateDirectory)/node_iterator.cpp$(ObjectSuffix): node_iterator.cpp $(IntermediateDirectory)/node_iterator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ashly Altman/Documents/GitHub/DataStructures/Chapter 4 and 5/Template_Node/node_iterator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/node_iterator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/node_iterator.cpp$(DependSuffix): node_iterator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/node_iterator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/node_iterator.cpp$(DependSuffix) -MM node_iterator.cpp

$(IntermediateDirectory)/node_iterator.cpp$(PreprocessSuffix): node_iterator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/node_iterator.cpp$(PreprocessSuffix) node_iterator.cpp

$(IntermediateDirectory)/bag.cpp$(ObjectSuffix): bag.cpp $(IntermediateDirectory)/bag.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Ashly Altman/Documents/GitHub/DataStructures/Chapter 4 and 5/Template_Node/bag.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bag.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bag.cpp$(DependSuffix): bag.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bag.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bag.cpp$(DependSuffix) -MM bag.cpp

$(IntermediateDirectory)/bag.cpp$(PreprocessSuffix): bag.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bag.cpp$(PreprocessSuffix) bag.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


