#ifndef  DOCUMENT_EXTRACTOR
#define  DOCUMENT_EXTRACTOR
#include "../HtmlDocument/HtmlDocument.h"
#incldue <DocumentInfo.h>
class DocumentExtractor
{
public:
    DocumentInfo extractInfo(HtmlDocument& doc);

};

#endif 