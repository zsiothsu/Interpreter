/*
 * @Author: your name
 * @Date: 1970-01-01 08:00:00
 * @LastEditTime: 2020-05-12 14:10:50
 * @Description: file content
 */
#ifndef ___INTERPRETER_H___
#define ___INTERPRETER_H___

#include <map>
#include <vector>
#include "Parser.h"
#include "any.h"

namespace AVSI
{   
    using std::map;
    using std::vector;

    class NodeVisitor
    {
   
    public:
        NodeVisitor(void);
        
        static any visitor(AST* node);
        static any AssignVisitor(AST* node);
        static any BinOpVisitor(AST* node);
        static any CompoundVisitor(AST* node);
        static any NumVisitor(AST* node);
        static any VariableVisitor(AST* node);
    };

    class Interpreter: public NodeVisitor
    {
    private:
        Parser* parser;
    public:
        Interpreter(void);
        Interpreter(Parser* parser);
        ~Interpreter();

        any interpret(void);
    };

    typedef any (*visiteNode)(AST* node);

    static map<TokenType,visiteNode> visitorMap = {
        {integer_ast    ,NodeVisitor::NumVisitor},
        {float_ast      ,NodeVisitor::NumVisitor},
        {add_opt        ,NodeVisitor::BinOpVisitor},
        {dec_opt        ,NodeVisitor::BinOpVisitor},
        {mul_opt        ,NodeVisitor::BinOpVisitor},
        {div_opt        ,NodeVisitor::BinOpVisitor},
        {assign_opt     ,NodeVisitor::AssignVisitor},
        {compound_ast   ,NodeVisitor::CompoundVisitor},
        {variable_ast   ,NodeVisitor::VariableVisitor}
    };

    static map<string,any> globalVariable = map<string,any>();
}

#endif