/*
 * @Author: your name
 * @Date: 2020-05-19
 * @LastEditTime: 2020-05-20 23:12:20
 * @Description: file content
 */ 
#ifndef ___NODEVISITOR_H___
#define ___NODEVISITOR_H___

#include "Parser.h"
#include "SymbolTable.h"

namespace AVSI
{
    using std::map;
    using std::string;
    
    class NodeVisitor
    {
    public:
        NodeVisitor(void) {};
        virtual ~NodeVisitor() {};

        virtual any visitor(AST* node) = 0;
        virtual any AssignVisitor(AST* node) = 0;
        virtual any BinOpVisitor(AST* node) = 0;
        virtual any CompoundVisitor(AST* node) = 0;
        virtual any FunctionVisitor(AST* node) = 0;
        virtual any NumVisitor(AST* node) = 0;
        virtual any UnaryOpVisitor(AST* node) = 0;
        virtual any VariableVisitor(AST* node) = 0;
    };

    typedef any (NodeVisitor::*visitNode)(AST* node);

    static map<string,visitNode> visitorMap = {
        {"NumVisitor"       ,&NodeVisitor::NumVisitor},
        {"BinOpVisitor"     ,&NodeVisitor::BinOpVisitor},
        {"UnaryOpVisitor"   ,&NodeVisitor::UnaryOpVisitor},
        {"FunctionVisitor"  ,&NodeVisitor::FunctionVisitor},
        {"AssignVisitor"    ,&NodeVisitor::AssignVisitor},
        {"CompoundVisitor"  ,&NodeVisitor::CompoundVisitor},
        {"VariableVisitor"  ,&NodeVisitor::VariableVisitor}
    };
}

#endif