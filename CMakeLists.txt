##########
# global #
##########

cmake_minimum_required( VERSION 2.8 )
project( robin C CXX )

# module settings
set( MODULE_VERSION_MAJOR 0 )
set( MODULE_VERSION_MINOR 1 )
set( MODULE_VERSION_PATCH 0 )
set( MODULE_VERSION "${MODULE_VERSION_MAJOR}.${MODULE_VERSION_MINOR}.${MODULE_VERSION_PATCH}" )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/" )

# rpath settings
if( APPLE )
	set( CMAKE_MACOSX_RPATH TRUE )
endif()
set( CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" )
set( CMAKE_SKIP_RPATH FALSE )
set( CMAKE_SKIP_BUILD_RPATH  FALSE )
set( CMAKE_BUILD_WITH_INSTALL_RPATH TRUE )

# utilities

include( RobinUtility )

#########
# flags #
#########

set( ROBIN_ENABLE_DEBUG_MESSAGES "false" CACHE BOOL "enable debug messages" )
if( ROBIN_ENABLE_DEBUG_MESSAGES )
	add_definitions( -DROBIN_ENABLE_DEBUG_MESSAGES )
endif()

add_definitions( -Wall )
add_definitions( -std=c++11 )

############
# external #
############

# threads
find_package( Threads REQUIRED )

# ssl
find_package( OpenSSL REQUIRED )

# event
find_package( Event REQUIRED )

# robin
set( robin_external_directories
	${OPENSSL_INCLUDE_DIR}
	${EVENT_INCLUDE_DIR}
)

set( robin_external_includes
	${OPENSSL_INCLUDE_DIR}
	${EVENT_INCLUDE_DIR}
)

set( robin_external_libraries 
	${OPENSSL_LIBRARIES}
	${EVENT_LIBRARIES}
)

link_directories( ${robin_external_directories} )
include_directories( ${robin_external_includes} )

###########
# utility #
###########

set( robin_utility_dependencies
)
set( robin_utility_directory
	utility
)
set( robin_utility_headers
	macros.hh
	initializer.hh
	singleton.hh
	error.hh
	message.hh
	ascii.hh
	binary.hh
	mutex.hh
	thread.hh
	typenull.hh
	typenode.hh
	typelist.hh
	typelength.hh
	typeat.hh
	typein.hh
	typeif.hh
	typechain.hh
)
set( robin_utility_sources
	error.cc
	message.cc
	ascii.cc
	binary.cc
	mutex.cc
	thread.cc
)

robin_library( utility )

########
# core #
########

set( robin_core_dependencies
	utility
)
set( robin_core_directory
	core
)
set( robin_core_headers
	bindable.hh
	buffer_sender.hh
	buffer_receiver.hh
)
set( robin_core_sources
	buffer_sender.cc
	buffer_receiver.cc
)

robin_library( core )

##################
# initialization #
##################

set( robin_initialization_dependencies
	utility
)
set( robin_initialization_directory
	initialization
)
set( robin_initialization_headers
	value.hh
	object.hh
	array.hh
	lingual.hh
	numerical.hh
	boolean.hh
	null.hh
	processor.hh
	arguments.hh
	lexer.hh
	reporter.hh
	serializer.hh
	evaluator.hh
	compiler.hh
	object_builder.hh
	lingual_builder.hh
	numerical_builder.hh
	boolean_builder.hh
	null_builder.hh
)
set( robin_initialization_sources
	value.cc
	object.cc
	array.cc
	lingual.cc
	numerical.cc
	boolean.cc
	null.cc
	processor.cc
	arguments.cc
	lexer.cc
	reporter.cc
	serializer.cc
	compiler.cc
	evaluator.cc
)

robin_library( initialization )

########
# main #
########

set( robin_main_dependencies
	utility
	initialization
)
set( robin_main_directory
	main
)
set( robin_main_programs
	robin
	echo
)

robin_executables( main )

########
# test #
########

set( robin_test_dependencies
	utility
	initialization
)
set( robin_test_directory
	test
)
set( robin_test_programs
	test_ascii
	test_binary
	test_builder
	test_lexer_compiler_reporter
	test_lexer_compiler_serializer
	test_lexer_reporter
	test_lexer_serializer
	test_message
	test_thread
	test_typeat
	test_typechain
	test_typelength
)

robin_executables( test )
