#ifndef Scanner_H
#define Scanner_H

namespace X {

class Scanner
{
public:
//     Scanner(Decode& decoder){m_scanner=zbar_scanner_create(decoder._decoder);}
//     Scanner(Decode* decoder=NULL){
//         zbar_decoder_t *zdcode=NULL;
//         if(decoder) zdcode=decoder->_decoder;
//         m_scanner=zbar_scanner_create(zdcode);
//     }
//     ~Scanner(){zbar_scanner_destroy(m_scanner);}
// public:
//     void reset(){
//         zbar_scanner_reset(m_scanner);
//     }
//     zbar_symbol_type_t new_scan(){
//         m_type=zbar_scanner_new_scan(m_scanner);
//         return m_type;
//     }

//     Zbar_symbol_type_t flush(){
//         m_type=zbar_scanner_flush(m_scanner);
//         return m_type;
//     }


// private:
//     zbar_scanner_t *m_scanner;
//     zbar_symbol_type_t m_type;
};

}
#endif // Scanner_H
