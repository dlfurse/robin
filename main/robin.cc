#include "arguments.hh"
#include "lexer.hh"
#include "compiler.hh"
#include "evaluator.hh"
#include "message.hh"
using namespace robin;

#include <iostream>
using std::cout;
using std::endl;

int main( int p_count, char** p_values )
{
    arguments t_arguments;
    t_arguments.required( "json" );

    try
    {
        t_arguments.start( p_count, p_values );
    }
    catch( const error& t_error )
    {
        msg_error( msg, "error occured in arguments:" << ret );
        msg_error( msg, "  " << t_error.what() << eom );
        return -1;
    }

    msg_normal( msg, "welcome to robin" << eom );
    msg_normal( msg, "processing..." << eom );

    lexer t_lexer;
    evaluator t_evaluator( t_arguments );
    compiler t_compiler;

    t_evaluator.insert_after( &t_lexer );
    t_compiler.insert_after( &t_evaluator );

    try
    {
        t_lexer( t_arguments.value< string >( "json" ) );
    }
    catch( const error& t_error )
    {
        msg_error( msg, "error occurred during lexing:" << ret );
        msg_error( msg, "  " << t_error.what() << eom );
        return -1;
    }

    try
    {
        t_arguments.stop();
    }
    catch( const error& t_error )
    {
        msg_error( msg, "an error occured in arguments:" << ret );
        msg_error( msg, "  " << t_error.what() << eom );
        return -1;
    }

    try
    {
        t_compiler();
    }
    catch( const error& t_error )
    {
        msg_error( msg, "error occurred during execution:" << ret );
        msg_error( msg, "  " << t_error.what() << eom );
        return -1;
    }

    msg_normal( msg, "...processing complete" << eom );
    msg_normal( msg, "goodbye" << eom );

    return 0;
}
