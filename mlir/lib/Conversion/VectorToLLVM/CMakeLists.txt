add_mlir_conversion_library(MLIRVectorToLLVM
  ConvertVectorToLLVM.cpp

  ADDITIONAL_HEADER_DIRS
  ${MLIR_MAIN_INCLUDE_DIR}/mlir/Conversion/VectorToLLVM

  DEPENDS
  MLIRConversionPassIncGen
)
set(LIBS
  MLIRLLVMIR
  MLIRStandardToLLVM
  MLIRVector
  MLIRTransforms
  LLVMCore
  LLVMSupport
  )

add_dependencies(MLIRVectorToLLVM ${LIBS})
target_link_libraries(MLIRVectorToLLVM
  PUBLIC
  ${LIBS})
