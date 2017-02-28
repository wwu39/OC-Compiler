# $Id: Makefile,v 1.1 2016-10-10 13:46:14-07 - - $

GPP      = g++ -std=gnu++14 -g -O0 -Wall -Wextra
MKDEP    = g++ -std=gnu++14 -MM

MKFILE   = Makefile
DEPFILE  = Makefile.dep
CSOURCES = astree.cpp lyutils.cpp auxlib.cpp string_set.cpp main.cpp \
           symstack.cpp symtable.cpp typecheck.cpp emit.cpp
SOURCES  = ${CSOURCES} ${CLGEN} ${CYGEN} 
HEADERS  = string_set.h auxlib.h astree.h lyutils.h type.h symtable.h
OBJECTS  = ${SOURCES:.cpp=.o}
EXECBIN  = oc
SRCFILES = ${HEADERS} ${SOURCES} ${MKFILE} README

# For Asg 2
LSOURCES = scanner.l
YSOURCES = parser.y
CLGEN    = yylex.cpp
HYGEN    = yyparse.h
CYGEN    = yyparse.cpp
LREPORT  = yylex.output
YREPORT  = yyparse.output

MKGEN    = *.oh *.lexyacctrace *.output *.log
ALLGEN   = ${CLGEN} ${CYGEN} ${HYGEN} ${MKGEN} *.str *.tok *.ast \
           *.sym *.oil


all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GPP} -o ${EXECBIN} ${OBJECTS}

# Special case to suppress comparison warning
yylex.o : yylex.cpp
	${GPP} -c -Wno-sign-compare $<

%.o : %.cpp
	${GPP} -c $<

# Scanner
${CLGEN} : ${LSOURCES}
	flex --outfile=${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^ ' ${LREPORT}

# Dummy Parser
${CYGEN} ${HYGEN} : ${YSOURCES}
	bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}

ci :
	cid + ${SRCFILES}

clean :
	-rm ${OBJECTS} ${DEPFILE} ${ALLGEN} *.oc*

spotless : clean
	- rm ${EXECBIN} Listing.ps Listing.pdf test.out

${DEPFILE} : ${CLGEN} ${CYGEN}
	${MKDEP} ${SOURCES} >${DEPFILE}

deps :  ${CLGEN} ${CYGEN}
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include ${DEPFILE}

test : ${EXECBIN}
	${EXECBIN} * * * >test.out 2>&1

lis : test
	mkpspdf Listing.ps ${SRCFILES} ${DEPFILE} test.out

again : ${SRCFILES}
	make --no-print-directory spotless dep ci test lis

submit: spotless
	submit cmps104a-wm.f16 asg5 *
