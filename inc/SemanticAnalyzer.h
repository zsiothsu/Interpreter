/*
 * @Author: your name
 * @Date: 1970-01-01 08:00:00
 * @LastEditTime: 2020-06-02 16:52:13
 * @Description: file content
 */
#ifndef ___SEMANTICANALYZER_H___
#define ___SEMANTICANALYZER_H___

#include "NodeVisitor.h"
#include "flags.h"

namespace AVSI {

    using std::clog;

    class SemanticAnalyzer : public NodeVisitor {
    private:
        SymbolTable *symbolTable;
        SymbolTable *currentSymbolTable;

    public:
        SemanticAnalyzer(void)
                : symbolTable(new SymbolTable(nullptr, "global", 1)),
                  currentSymbolTable(symbolTable) {};

        virtual ~SemanticAnalyzer();

        any visitor(AST *node);

        any AssignVisitor(AST *node);

        any BinOpVisitor(AST *node);

        any BooleanVisitor(AST *node);

        any CompoundVisitor(AST *node);

        any EchoVisitor(AST *node);

        any ForVisitor(AST *node);

        any FunctionDeclVisitor(AST *node);

        any FunctionCallVisitor(AST *node);

        any GlobalVisitor(AST *node);

        any IfVisitor(AST *node);

        any InputVisitor(AST *node);

        any NumVisitor(AST *node);

        any PrintfVisitor(AST *node);

        any ReturnVisitor(AST *node);

        any StringVisitor(AST *node);

        any UnaryOpVisitor(AST *node);

        any VariableVisitor(AST *node);

        any WhileVisitor(AST *node);

        SymbolTable *SemanticAnalyze(AST *root);
    };
} // namespace AVSI

#endif