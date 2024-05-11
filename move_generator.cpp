#define setBit(bitboard, square) ((bitboard) |= (1ULL << (square)))
#define getBit(bitboard, square) ((bitboard) & (1ULL << (square)))
#define popBit(bitboard, square) ((bitboard) &= ~(1ULL << (square)))
#define U64 unsigned long long

 


#define copy_board()                                                      \
    U64 bitboards_copy[12], occupancies_copy[3];                          \
    int side_copy, enpassant_copy, castle_copy;                           \
    memcpy(bitboards_copy, bitboards, 96);                                \
    memcpy(occupancies_copy, occupancies, 24);                            \
    side_copy = side, enpassant_copy = enpassant, castle_copy = castle;   \
    int temp_white_castle = white_castle, temp_balck_castle = black_castle;\
     

// restore board state
#define take_back()                                                       \
    memcpy(bitboards, bitboards_copy, 96);                                \
    memcpy(occupancies, occupancies_copy, 24);                            \
    side = side_copy, enpassant = enpassant_copy, castle = castle_copy;   \
    white_castle = temp_white_castle, black_castle = temp_balck_castle;     \
    

static inline int is_square_attacked(int square, int side);
void print_position();
static inline int count_bits(unsigned long long board);
int get_ls1b_index(unsigned long long board);
unsigned long long mask_pawn_attacks(int side, int i);
unsigned long long mask_knight_attacks(int i);
unsigned long long mask_king_attacks(int i);
unsigned long long mask_bishop_attacks(int i);
unsigned long long mask_all_bishop_attacks(int i, unsigned long long block);
unsigned long long mask_rook_attacks(int i);
unsigned long long mask_all_rook_attacks(int i, unsigned long long block);
void print_bitboard(unsigned long long bitboard);
void init_attacks();
unsigned long long set_occupancy(int index, int bits_in_mask, U64 attack_mask);
void init_sliders_attacks(int bishop);
static inline U64 get_bishop_attacks(int square, U64 occupancy);
static inline U64 get_rook_attacks(int square, U64 occupancy);
static inline U64 get_queen_attacks(int square, U64 occupancy);
void parse_fen(string fen);
vector<int> generate_moves();
void print_position();
static inline int is_square_attacked(int square, int side);
void print_attacked_squares(int side);
int eval();
void make_move(int move);
string ret_str_move(int int_move);
int quiesce(int dep, int alpha, int beta);

int white_castle = 0, black_castle = 0;

#define tricky_position "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 "

 
unsigned long long one = 1;
unsigned long long pawn_attacks[2][64];
unsigned long long knight_attacks[64];
unsigned long long king_attacks[64];
U64 bishop_masks[64];
U64 bitboards[12];
int side = -1;
int castle = 0;
int halfmove = 0;
int fullmove = 0;
int enpassant = -1;


U64 occupancies[3];
U64 rook_masks[64];


U64 bishop_attacks[64][512];


U64 rook_attacks[64][4096];
unsigned long long no_A = 18374403900871474942ULL;
unsigned long long no_B = 18302063728033398269ULL;
unsigned long long no_C = 18157383382357244923ULL;
unsigned long long no_D = 17868022691004938231ULL;
unsigned long long no_E = 17289301308300324847ULL;
unsigned long long no_F = 16131858542891098079ULL;
unsigned long long no_G = 13816973012072644543ULL;
unsigned long long no_H = 9187201950435737471ULL;


unsigned long long no_AB = 18229723555195321596ULL;
unsigned long long no_HG = 4557430888798830399ULL;
enum {
a8, b8, c8, d8, e8, f8, g8, h8,
a7, b7, c7, d7, e7, f7, g7, h7,
a6, b6, c6, d6, e6, f6, g6, h6,
a5, b5, c5, d5, e5, f5, g5, h5,
a4, b4, c4, d4, e4, f4, g4, h4,
a3, b3, c3, d3, e3, f3, g3, h3,
a2, b2, c2, d2, e2, f2, g2, h2,
a1, b1, c1, d1, e1, f1, g1, h1


};


struct moveL{
        int moves[250];

        int size = 0;
};

enum { wk = 1, wq = 2, bk = 4, bq = 8 };

enum { P, N, B, R, Q, K, p, n, b, r, q, k };

string pieces = "PNBRQKpnbrqk";

map<char, int>back;
map<string, int>square_back;
const int bishop_relevant_bits[64] = {
        6,5,5,5,5,5,5,6,
        5,5,5,5,5,5,5,5,
        5,5,7,7,7,7,5,5,
        5,5,7,9,9,7,5,5,
        5,5,7,9,9,7,5,5,
        5,5,7,7,7,7,5,5,
        5,5,5,5,5,5,5,5,
        6,5,5,5,5,5,5,6

};
const int rook_relevant_bits[64] = {
        12,11,11,11,11,11,11,12,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        12,11,11,11,11,11,11,12
};
string coordinate[] = {
        "a8","b8","c8","d8","e8","f8","g8","h8",
        "a7","b7","c7","d7","e7","f7","g7","h7",
        "a6","b6","c6","d6","e6","f6","g6","h6",
        "a5","b5","c5","d5","e5","f5","g5","h5",
        "a4","b4","c4","d4","e4","f4","g4","h4",
        "a3","b3","c3","d3","e3","f3","g3","h3",
        "a2","b2","c2","d2","e2","f2","g2","h2",
        "a1","b1","c1","d1","e1","f1","g1","h1"
};

U64 rook_magic_numbers[64] = {
    0x8a80104000800020ULL,
    0x140002000100040ULL,
    0x2801880a0017001ULL,
    0x100081001000420ULL,
    0x200020010080420ULL,
    0x3001c0002010008ULL,
    0x8480008002000100ULL,
    0x2080088004402900ULL,
    0x800098204000ULL,
    0x2024401000200040ULL,
    0x100802000801000ULL,
    0x120800800801000ULL,
    0x208808088000400ULL,
    0x2802200800400ULL,
    0x2200800100020080ULL,
    0x801000060821100ULL,
    0x80044006422000ULL,
    0x100808020004000ULL,
    0x12108a0010204200ULL,
    0x140848010000802ULL,
    0x481828014002800ULL,
    0x8094004002004100ULL,
    0x4010040010010802ULL,
    0x20008806104ULL,
    0x100400080208000ULL,
    0x2040002120081000ULL,
    0x21200680100081ULL,
    0x20100080080080ULL,
    0x2000a00200410ULL,
    0x20080800400ULL,
    0x80088400100102ULL,
    0x80004600042881ULL,
    0x4040008040800020ULL,
    0x440003000200801ULL,
    0x4200011004500ULL,
    0x188020010100100ULL,
    0x14800401802800ULL,
    0x2080040080800200ULL,
    0x124080204001001ULL,
    0x200046502000484ULL,
    0x480400080088020ULL,
    0x1000422010034000ULL,
    0x30200100110040ULL,
    0x100021010009ULL,
    0x2002080100110004ULL,
    0x202008004008002ULL,
    0x20020004010100ULL,
    0x2048440040820001ULL,
    0x101002200408200ULL,
    0x40802000401080ULL,
    0x4008142004410100ULL,
    0x2060820c0120200ULL,
    0x1001004080100ULL,
    0x20c020080040080ULL,
    0x2935610830022400ULL,
    0x44440041009200ULL,
    0x280001040802101ULL,
    0x2100190040002085ULL,
    0x80c0084100102001ULL,
    0x4024081001000421ULL,
    0x20030a0244872ULL,
    0x12001008414402ULL,
    0x2006104900a0804ULL,
    0x1004081002402ULL
};

// bishop magic numbers
U64 bishop_magic_numbers[64] = {
    0x40040844404084ULL,
    0x2004208a004208ULL,
    0x10190041080202ULL,
    0x108060845042010ULL,
    0x581104180800210ULL,
    0x2112080446200010ULL,
    0x1080820820060210ULL,
    0x3c0808410220200ULL,
    0x4050404440404ULL,
    0x21001420088ULL,
    0x24d0080801082102ULL,
    0x1020a0a020400ULL,
    0x40308200402ULL,
    0x4011002100800ULL,
    0x401484104104005ULL,
    0x801010402020200ULL,
    0x400210c3880100ULL,
    0x404022024108200ULL,
    0x810018200204102ULL,
    0x4002801a02003ULL,
    0x85040820080400ULL,
    0x810102c808880400ULL,
    0xe900410884800ULL,
    0x8002020480840102ULL,
    0x220200865090201ULL,
    0x2010100a02021202ULL,
    0x152048408022401ULL,
    0x20080002081110ULL,
    0x4001001021004000ULL,
    0x800040400a011002ULL,
    0xe4004081011002ULL,
    0x1c004001012080ULL,
    0x8004200962a00220ULL,
    0x8422100208500202ULL,
    0x2000402200300c08ULL,
    0x8646020080080080ULL,
    0x80020a0200100808ULL,
    0x2010004880111000ULL,
    0x623000a080011400ULL,
    0x42008c0340209202ULL,
    0x209188240001000ULL,
    0x400408a884001800ULL,
    0x110400a6080400ULL,
    0x1840060a44020800ULL,
    0x90080104000041ULL,
    0x201011000808101ULL,
    0x1a2208080504f080ULL,
    0x8012020600211212ULL,
    0x500861011240000ULL,
    0x180806108200800ULL,
    0x4000020e01040044ULL,
    0x300000261044000aULL,
    0x802241102020002ULL,
    0x20906061210001ULL,
    0x5a84841004010310ULL,
    0x4010801011c04ULL,
    0xa010109502200ULL,
    0x4a02012000ULL,
    0x500201010098b028ULL,
    0x8040002811040900ULL,
    0x28000010020204ULL,
    0x6000020202d0240ULL,
    0x8918844842082200ULL,
    0x4010011029020020ULL
};

int king_attacked = 0;

U64 piece_key[12][64];

U64 enpassant_key[64];

U64 castle_key[16];

U64 side_key;

U64 hash_key;


enum { white, black, both };
int key = 0;


void make_move(int move){
       
        int pro = move & 7;
        move  = (move >> 3);
        int targeted_square = move & 63;
        move = (move >> 8); 
        int source_square = move & 63;
        int piece1 = 0, piece2 = -1;
        for(int x = P; x <= k; ++x){
                if(getBit(bitboards[x], source_square)){
                        piece1 = x;
                }
                if(getBit(bitboards[x], targeted_square)){
                        piece2 = x;
                }
        }
       
        
       U64 temptar = getBit(occupancies[both], targeted_square);
        popBit(bitboards[piece1], source_square);
        popBit(occupancies[both], source_square);
        popBit(occupancies[side], source_square);
        setBit(bitboards[piece1], targeted_square);
        setBit(occupancies[side], targeted_square);
        setBit(occupancies[both], targeted_square);
        
        if((piece1 == P || piece1 == p) && (abs(targeted_square - source_square) != 8 && abs(targeted_square - source_square) != 16  ) && !temptar){
                     //cout<<move<<"difference = "<<abs(targeted_square - source_square)<<'\n';
                      targeted_square = (side == white ? targeted_square + 8 : targeted_square - 8);
                      piece2 = (side == white ? p : P);  
                      popBit(occupancies[both], targeted_square);
                     // cout<<"piece2 = "<<piece2<<" targeted square = "<<coordinate[targeted_square]<<'\n';
        }
        if(piece2 != -1){
                
                popBit(bitboards[piece2], targeted_square);
                popBit(occupancies[side ^ 1], targeted_square);
                }

        if(side == white){
                int index = get_ls1b_index(bitboards[K]);
                if(is_square_attacked(index, black)) king_attacked = 1;
        }
        else{
                int index = get_ls1b_index(bitboards[k]);
                if(is_square_attacked(index, white)) king_attacked = 1;
        }
       // enum { wk = 1, wq = 2, bk = 4, bq = 8 };
        if(piece1 == K){
                if(source_square == 60 && targeted_square == 62){
                        popBit(bitboards[R], h1);
                        popBit(occupancies[white], h1);
                        popBit(occupancies[both], h1);
                        setBit(bitboards[R], f1);
                        setBit(occupancies[white], f1);
                        setBit(occupancies[both], f1);
                        white_castle = 1;

                        hash_key ^= piece_key[R][h1];
                        hash_key ^= piece_key[R][f1];

                }
                else if(source_square == 60 && targeted_square == 58){
                        popBit(bitboards[R], a1);
                        popBit(occupancies[white], a1);
                        popBit(occupancies[both], a1);
                        setBit(bitboards[R], d1);
                        setBit(occupancies[white], d1);
                        setBit(occupancies[both], d1);
                        white_castle = 1;
                        hash_key ^= piece_key[R][a1];
                        hash_key ^= piece_key[R][d1];
                }

                castle &= 12;
        }
        else if(piece1 == k){
                  if(source_square == 4 && targeted_square == 6){
                        popBit(bitboards[r], h8);
                        popBit(occupancies[black], h8);
                        popBit(occupancies[both], h8);
                        setBit(bitboards[r], f8);
                        setBit(occupancies[black], f8);
                        setBit(occupancies[both], f8);
                        black_castle = 1;
                        hash_key ^= piece_key[r][h8];
                        hash_key ^= piece_key[r][f8];

                }
                else if(source_square == 4 && targeted_square == 2){
                        popBit(bitboards[r], a8);
                        popBit(occupancies[black], a8);
                        popBit(occupancies[both], a8);
                        setBit(bitboards[r], d8);
                        setBit(occupancies[black], d8);
                        setBit(occupancies[both], d8);
                        black_castle = 1;
                        hash_key ^= piece_key[r][a8];
                        hash_key ^= piece_key[r][d8];
                }

                castle &= 3;
        }

        if((piece1 == R && source_square == h1) || targeted_square == h1) castle &= 14;
        else if((piece1 == R && source_square == a1) || targeted_square == a1) castle &= 13;
        else if((piece1 == r && source_square == h8) || targeted_square == h8) castle &= 11;
        else if((piece1 == r && source_square == a8) || targeted_square == a8) castle &= 7;

        if(pro != 0){
                popBit(bitboards[(side == white ? P : p)], targeted_square);

                if(pro == 1){
                        setBit(bitboards[(side == white ? R : r)], targeted_square);    
                }
                else if(pro == 2){
                        setBit(bitboards[(side == white ? B : b)], targeted_square);    
                }
                else if(pro == 3){
                        setBit(bitboards[(side == white ? Q : q)], targeted_square);
                }
                else{
                        setBit(bitboards[(side == white ? N : n)], targeted_square);
                }

        }

        if(abs(source_square - targeted_square) == 16 && (piece1 == p || piece1 == P)){
                enpassant = (side == white ? targeted_square + 8 : targeted_square - 8);
        }
        else{
                enpassant = -1;
        }
        
        side ^= 1;

}


static inline int count_bits(unsigned long long board){
        int count = 0;
        while(board){
                board &= (board - 1);
                count++;
        }
        return count;
}
int get_ls1b_index(unsigned long long board){

        if(board)
                return count_bits((board & -board) - 1);
        else 
                return -1;
}

unsigned long long mask_pawn_attacks(int side, int i){
        unsigned long long bitboard = 0;
                setBit(bitboard, i);
               unsigned long long pawn_attack = 0;
                
                if(side == white){
               if((bitboard >> 7 ) & no_A)pawn_attack |= (bitboard >> 7);
               if((bitboard >> 9 ) & no_H)pawn_attack |= (bitboard >> 9);
                return pawn_attack;
                }

                if((bitboard << 7 ) & no_H)pawn_attack |= (bitboard << 7);
                if((bitboard << 9 ) & no_A)pawn_attack |= (bitboard << 9);

                return pawn_attack;
                        
}
unsigned long long mask_knight_attacks(int i){
        unsigned long long bitboard = 0;
                setBit(bitboard, i);
                unsigned long long knight_attack = 0;
                if((bitboard >> 17 & no_H)) knight_attack |= (bitboard >> 17);
                if((bitboard >> 15 & no_A)) knight_attack |= (bitboard >> 15);
                if((bitboard >> 10 & no_HG)) knight_attack |= (bitboard >> 10);
                if((bitboard >> 6 & no_AB)) knight_attack |= (bitboard >> 6);
                if((bitboard << 17 & no_A)) knight_attack |= (bitboard << 17);
                if((bitboard << 15 & no_H)) knight_attack |= (bitboard << 15);
                if((bitboard << 10 & no_AB)) knight_attack |= (bitboard << 10);
                if((bitboard << 6 & no_HG)) knight_attack |= (bitboard << 6);

                return knight_attack;
        
}

unsigned long long mask_king_attacks(int i){
        unsigned long long bitboard = 0;
        unsigned long long king_attack = 0;
        
                bitboard = 0;
                setBit(bitboard, i);
                if((bitboard >> 8)) king_attack |= (bitboard >> 8);
                if((bitboard >> 9 & no_H)) king_attack |= (bitboard >> 9);
                if((bitboard >> 7 & no_A))king_attack |= (bitboard >> 7);
                if((bitboard >> 1 & no_H)) king_attack |= (bitboard >> 1);
                if((bitboard << 8 )) king_attack |= (bitboard << 8);
                if((bitboard << 9 & no_A)) king_attack |= (bitboard << 9);
                if((bitboard << 7 & no_H)) king_attack |= (bitboard << 7);
                if((bitboard << 1 & no_A)) king_attack |= (bitboard << 1);
        return king_attack;
}


unsigned long long mask_bishop_attacks(int i){
        
               unsigned long long bishop_attack = 0;
                int temp = i / 8;
                int temp1 = i % 8;

                for(int r = temp + 1, f = temp1 + 1; r <= 6 && f <= 6; r++, f++ ) bishop_attack |= (one << (r * 8 + f) );
                for(int r = temp - 1 , f = temp1 + 1; r >= 1 && f <= 6; r--, f++ ) bishop_attack |= (one << (r * 8 + f) );
                for(int r = temp - 1, f = temp1 - 1; r >= 1 && f >= 1; r--, f-- ) bishop_attack |= (one << (r * 8 + f) );
                for(int r = temp + 1, f = temp1 - 1; r <= 6 && f >= 1; r++, f-- ) bishop_attack |= (one << (r * 8 + f) );

                return bishop_attack;

}

unsigned long long mask_all_bishop_attacks(int i, unsigned long long block){
        
               unsigned long long bishop_attack = 0;
                int temp = i / 8;
                int temp1 = i % 8;

                for(int r = temp + 1, f = temp1 + 1; r <= 7 && f <= 7; r++, f++ ) {
                        bishop_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }
                for(int r = temp - 1 , f = temp1 + 1; r >= 0 && f <= 7; r--, f++ ) {
                        bishop_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }
                for(int r = temp - 1, f = temp1 - 1; r >= 0 && f >= 0; r--, f-- ) {
                        bishop_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }
                for(int r = temp + 1, f = temp1 - 1; r <= 7 && f >= 0; r++, f-- ) {
                        bishop_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }

                return bishop_attack;

}


unsigned long long mask_rook_attacks(int i){
        
               unsigned long long rook_attack = 0;
                int temp = i / 8;
                int temp1 = i % 8;

                for(int r = temp + 1, f = temp1; r <= 6; r++ ) rook_attack |= (one << (r * 8 + f) );
                for(int r = temp - 1 , f = temp1; r >= 1 ; r-- ) rook_attack |= (one << (r * 8 + f) );
                for(int r = temp, f = temp1 - 1;  f >= 1;  f-- ) rook_attack |= (one << (r * 8 + f) );
                for(int r = temp, f = temp1 + 1;  f <= 6; f++ ) rook_attack |= (one << (r * 8 + f) );

                return rook_attack;      
}

unsigned long long mask_all_rook_attacks(int i, unsigned long long block){
        
               unsigned long long rook_attack = 0;
                int temp = i / 8;
                int temp1 = i % 8;

                for(int r = temp + 1, f = temp1; r <= 7; r++ ) {
                        rook_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }
                for(int r = temp - 1 , f = temp1; r >= 0 ; r-- ) {
                        rook_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }
                for(int r = temp, f = temp1 - 1;  f >= 0;  f-- ) {
                        rook_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }
                for(int r = temp, f = temp1 + 1;  f <= 7; f++ ) {
                        rook_attack |= (one << (r * 8 + f) );
                        if(block & (one << (r * 8 + f)))break;
                }

                return rook_attack;      
}
void print_bitboard(unsigned long long bitboard){
        
        for(int rank = 0; rank < 8; ++rank){
                cout<<(8 - rank)<<"  ";
                for(int file = 0; file < 8; ++file){
                        int square = 8 * rank + file;
                        cout<<(((one << square)&(bitboard)) ? 1 : 0 )<<' ';
                }
                cout<<'\n';
        }
        cout<<'\n';

        cout<<"   a b c d e f g h\n";

}

void init_attacks(){
        for(int i = 0; i < 64; ++i){
                pawn_attacks[white][i] = mask_pawn_attacks(white, i);
                pawn_attacks[black][i] = mask_pawn_attacks(black, i);

                king_attacks[i] = mask_king_attacks(i);

                knight_attacks[i] = mask_knight_attacks(i);
        }

        for(int i = 0; i < 12; ++i){
                back[pieces[i]] = i;
        }

        for(int i = 0; i < 64; ++i){
                square_back[coordinate[i]] = i;

        }
}


//*****************************************************************************************************************************************************
// this code taken from : https://github.com/maksimKorzh/chess_programming/blob/master/src/bbc/encodeing_decoding_moves/bbc.c
U64 set_occupancy(int index, int bits_in_mask, U64 attack_mask)                                                                                       
{
    
    U64 occupancy = 0ULL;
    
        for (int count = 0; count < bits_in_mask; count++)
    {
        
        int square = get_ls1b_index(attack_mask);
        
        
        popBit(attack_mask, square);
      
        
        if (index & (1 << count))
            
            occupancy |= (1ULL << square);
    }
    
  
    return occupancy;
}


void init_sliders_attacks(int bishop)
{
    
    for (int square = 0; square < 64; square++)
    {
        
        bishop_masks[square] = mask_bishop_attacks(square);
        rook_masks[square] = mask_rook_attacks(square);
        
        
        U64 attack_mask = bishop ? bishop_masks[square] : rook_masks[square];
        
        
        int relevant_bits_count = count_bits(attack_mask);
        
        
        int occupancy_indicies = (1 << relevant_bits_count);
        
        
        for (int index = 0; index < occupancy_indicies; index++)
        {
            
            if (bishop)
            {
                
                U64 occupancy = set_occupancy(index, relevant_bits_count, attack_mask);
                
                int magic_index = (occupancy * bishop_magic_numbers[square]) >> (64 - bishop_relevant_bits[square]);
                
                
                bishop_attacks[square][magic_index] = mask_all_bishop_attacks(square, occupancy);
            }
            
            // rook
            else
            {
                
                U64 occupancy = set_occupancy(index, relevant_bits_count, attack_mask);
                
                
                int magic_index = (occupancy * rook_magic_numbers[square]) >> (64 - rook_relevant_bits[square]);
                
                
                rook_attacks[square][magic_index] = mask_all_rook_attacks(square, occupancy);
            
            }
        }
    }
}


static inline U64 get_bishop_attacks(int square, U64 occupancy)
{
    
    occupancy &= bishop_masks[square];
    occupancy *= bishop_magic_numbers[square];
    occupancy >>= 64 - bishop_relevant_bits[square];
    
    
    return bishop_attacks[square][occupancy];
}

static inline U64 get_rook_attacks(int square, U64 occupancy)
{
    
    occupancy &= rook_masks[square];
    occupancy *= rook_magic_numbers[square];
    occupancy >>= 64 - rook_relevant_bits[square];
    
    
    return rook_attacks[square][occupancy];
}

static inline U64 get_queen_attacks(int square, U64 occupancy)
{
    
    
    return get_rook_attacks(square, occupancy) | get_bishop_attacks(square, occupancy);
}

//*************************************************************************************************************************************************






int co = 0;
void parse_fen(string fen){
         memset(bitboards, 0ULL, sizeof(bitboards));
    
    // reset occupancies (bitboards)
        memset(occupancies, 0ULL, sizeof(occupancies));
    
        // reset game state variables
        side = 0;
        enpassant = -1;
        castle = 0;
        int n = fen.size();
        int stage = 1;
        int rank = 0, file = 0;
        for(int i = 0; i < n; ++i){

                if(stage == 1){
                     
                        
                        if(fen[i] == '/'){
                                rank++;
                                file = 0;
                        }
                        else if(int (fen[i]) == 32){
                                stage++;
                                
                        }
                        else{
                                if((fen[i] >= 'a' && fen[i] <= 'z') || (fen[i] >= 'A' && fen[i] <= 'Z')){
                                        int index = back[fen[i]];
                                        int square = 8 * rank + file;
                                        setBit(bitboards[index], square);
                                        setBit(occupancies[2], square);
                                        if((fen[i] >= 'a' && fen[i] <= 'z')){
                                                setBit(occupancies[1], square);
                                        }
                                        else{
                                                setBit(occupancies[0], square);
                                        }       
                                        file++;

                                }
                                else{
                                        int x = (fen[i] - '0');
                                        file += (x);
                                }
                        }
                }
                else if(stage == 2){
                        if(int (fen[i]) == 32){
                                stage++;
                        }
                        else{
                               if(fen[i] == 'w'){
                                       side = 0;
                               }
                               else {
                                       side = 1;
                               }
                        }

                }
                else if(stage == 3){
                         if(int (fen[i]) == 32){
                                stage++;
                        }
                        else{
                               if(fen[i] == 'K'){
                                       castle |= wk;
                               }
                               else if (fen[i] == 'Q'){
                                       castle |= wq;
                               }
                               else if(fen[i] == 'k'){
                                       castle |= bk;
                               }
                               else if(fen[i] == 'q'){
                                       castle |= bq;
                               }
                        }
                }
                else if(stage == 4){
                         if(int (fen[i]) == 32){
                                stage++;
                        }
                        else{
                               if(fen[i] != '-'){
                                      string s = "";
                                       s = fen[i];
                                       s += fen[i + 1];
                                       i++;
                                       enpassant = square_back[s];
                               }
                              
                        }
                }
                else if(stage == 5){
                        if(int (fen[i]) == 32){
                                stage++;
                        }
                        else{
                               if(fen[i] != '-'){
                                       int x = (fen[i] - '0');
                                       halfmove = x;
                               }
                              
                        }
                }
                else if(stage == 6){
                        if(int (fen[i]) == 32){
                                stage++;
                        }
                        else{
                               if(fen[i] != '-'){
                                       int x = (fen[i] - '0');
                                       fullmove = x;
                               }
                              
                        }
                }
                


        }

}


void generate_moves(moveL & moves){
        int sz = 0;
        U64 cbitboard, attacks;
        int index, source_square, targeted_square, move = 0 ;
        for(int piece = P; piece <= k; ++piece){

                if(side == white){
                        if(piece == P){
                                cbitboard = bitboards[P];      

                                while(cbitboard){
                                        index = get_ls1b_index(cbitboard);
                                        source_square = index;
                                        targeted_square = index - 8;               
                                        if(index >= a7 && index <= h7 && !getBit(occupancies[both], targeted_square)){
                                                
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 1);
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 2);
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 3);
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 4);                
                                        }
                                        else{
                                                if(!getBit(occupancies[both], targeted_square)){
                                
                                               // cout<<"push pawn "<<coordinate[source_square]<<coordinate[targeted_square]<<"\n";
                                                 moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                                 targeted_square -= 8;       
                                                        if(index >= a2 && index <= h2 &&!getBit(occupancies[both], targeted_square)){
                                                       // cout<<"double push "<<coordinate[source_square]<<coordinate[targeted_square - 8]<<"\n";
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                                        }
                                                }
                                                 
                                        }

                                        attacks = pawn_attacks[white][source_square] & occupancies[black];

                                        while(attacks){
                                                targeted_square = get_ls1b_index(attacks);
                                                
                                                 if(index >= a7 && index <= h7){
                                                
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"r\n";
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"q\n";
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"n\n";
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"b\n";

                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 1);
                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 2);
                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 3);
                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 4);                
                                        }
                                        else{
                                                       // cout<<"capture: "<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                        }
                                                popBit(attacks, targeted_square);
                                        }

                                          if(enpassant != -1){
                                                U64 enpassant_attack = pawn_attacks[white][source_square] & (one << enpassant);

                                                if(enpassant_attack){
                                               // cout<<"enpassant move "<<coordinate[source_square]<<coordinate[enpassant]<<'\n';

                                               moves.moves[sz++] = (((move | source_square) << 11) | ((move | enpassant) << 3));
                                                } 
                                        }

                                        popBit(cbitboard, index);
                                }

                               
                        }
                        // generate castling moves

                        if(piece == K){
                                cbitboard = bitboards[K];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = king_attacks[source_square] & (~occupancies[white]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[black], targeted_square)){
                                                       //cout<<"King captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"King move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               }

                                if(castle & wk){
                                        if(!getBit(occupancies[both], f1) && !getBit(occupancies[both], g1)){
                                                if(!is_square_attacked(e1, black) && !is_square_attacked(f1, black) && !is_square_attacked(g1, black) ){
                                                        //cout<<"castle move e1g1\n";
                                                        // g1 = 62 e1 = 60
                                                        moves.moves[sz++] = ((1 << 19) | ((move | e1) << 11) | ((move | g1) << 3));
                                                }
                                        }
                                }

                                if(castle & wq){
                                        if(!getBit(occupancies[both], d1) && !getBit(occupancies[both], c1) && !getBit(occupancies[both], b1)){
                                                if(!is_square_attacked(e1, black) && !is_square_attacked(c1, black) && !is_square_attacked(d1, black) ){
                                                        //cout<<"castle move e1c1\n";
                                                        moves.moves[sz++] = ((1 << 19) | ((move | e1) << 11) | ((move | c1) << 3));
                                                }
                                        }
                                }
                        }
                        // generate knights moves
                        if(piece == N){
                               cbitboard = bitboards[N];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = knight_attacks[source_square] & (~occupancies[white]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[black], targeted_square)){
                                                       //cout<<"Knight captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"Knight move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }
                        // generate bishop moves
                        if(piece == B){
                                cbitboard = bitboards[B];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = get_bishop_attacks(source_square, occupancies[both]) & (~occupancies[white]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[black], targeted_square)){
                                                       //cout<<"Bishop captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"Bishop move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }
                        //generate rook attacks for white 
                        if(piece == R){
                                cbitboard = bitboards[R];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = get_rook_attacks(source_square, occupancies[both]) & (~occupancies[white]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[black], targeted_square)){
                                                       //cout<<"Rook captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"Rook move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }
                        if(piece == Q){
                                cbitboard = bitboards[Q];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = get_queen_attacks(source_square, occupancies[both]) & (~occupancies[white]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[black], targeted_square)){
                                                       //cout<<"Queen captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"Queen move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }       

                }

                else{
                     if(piece == p){
                                cbitboard = bitboards[p];      

                                while(cbitboard){
                                        index = get_ls1b_index(cbitboard);
                                        source_square = index;
                                        targeted_square = index + 8;               
                                        if(index >= a2 && index <= h2 && !getBit(occupancies[both], targeted_square)){
                                                
                                                //cout<<coordinate[source_square]<<coordinate[targeted_square]<<"r\n";
                                                //cout<<coordinate[source_square]<<coordinate[targeted_square]<<"q\n";
                                                //cout<<coordinate[source_square]<<coordinate[targeted_square]<<"n\n";
                                                //cout<<coordinate[source_square]<<coordinate[targeted_square]<<"b\n";

                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 1);
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 2);
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 3);
                                                moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3) | 4);                
                                        }
                                        else{
                                                if(!getBit(occupancies[both], targeted_square)){
                                                //cout<<coordinate[source_square]<<coordinate[targeted_square]<<"\n";
                                                        moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                                        targeted_square += 8;
                                                        if(index >= a7 && index <= h7 &&!getBit(occupancies[both], targeted_square)){
                                                        //cout<<coordinate[source_square]<<coordinate[targeted_square + 8]<<"\n";
                                                        moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                                        }
                                                }
                                                 
                                        }

                                        attacks = pawn_attacks[black][source_square] & occupancies[white];

                                        while(attacks){
                                                targeted_square = get_ls1b_index(attacks);
                                                
                                                 if(index >= a2 && index <= h2){
                                                
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"r\n";
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"q\n";
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"n\n";
                                                //cout<<"capture with pormotion "<<coordinate[source_square]<<coordinate[targeted_square]<<"b\n";

                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 1);
                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 2);
                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 3);
                                                moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3) | 4);                
                                        }
                                        else{
                                                        //cout<<"capture: "<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                        moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                        }
                                                popBit(attacks, targeted_square);
                                        }

                                          if(enpassant != -1){
                                                U64 enpassant_attack = pawn_attacks[black][source_square] & (one << enpassant);

                                                if(enpassant_attack){
                                                        //cout<<"enpassant move "<<coordinate[source_square]<<coordinate[enpassant]<<'\n';
                                                        moves.moves[sz++] = (((move | source_square) << 11) | ((move | enpassant) << 3));
                                                } 
                                        }
                                      
                                        popBit(cbitboard, index);
                                }
                        }

                        // generate king attacks
                        if(piece == k){
                                cbitboard = bitboards[k];

                               while(cbitboard){
                                       //cout<<"Hello\n"; 
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = king_attacks[source_square] & (~occupancies[black]); 
                                       while(attacks){
                                                
                                               //print_bitboard(attacks);
                                               //cout<<"Hello\n";
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[white], targeted_square)){
                                                       //cout<<"King captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                                       //cout<<(((move | source_square) << 11) | ((move | targeted_square) << 3))<<'\n';
                                                       //cout<<"source_square = "<<coordinate[source_square]<< "targeted_square = "<<coordinate[targeted_square]<<'\n';
                                                       //cout<<ret_str_move(((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"King move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               }

                                if(castle & bk){
                                        if(!getBit(occupancies[both], f8) && !getBit(occupancies[both], g8)){
                                                if(!is_square_attacked(e8, white) && !is_square_attacked(f8, white) && !is_square_attacked(g8, white) ){
                                                        //cout<<"castle move e8g8\n";
                                                        moves.moves[sz++] = ((1 << 19) | ((move | 4) << 11) | ((move | 6) << 3));
                                                }
                                        }
                                }

                                if(castle & bq){
                                        if(!getBit(occupancies[both], d8) && !getBit(occupancies[both], c8) && !getBit(occupancies[both], b8)){
                                                if(!is_square_attacked(e8, white) && !is_square_attacked(c8, white) && !is_square_attacked(d8, white) ){
                                                        //cout<<"castle move e8c8\n";
                                                        moves.moves[sz++] = ((1 << 19) | ((move | 4) << 11) | ((move | 2) << 3));
                                                }
                                        }
                                }
                        }
                        //generate knight moves
                        if(piece == n){
                               cbitboard = bitboards[n];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = knight_attacks[source_square] & (~occupancies[black]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[white], targeted_square)){
                                                       //cout<<"Knight captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"Knight move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }
                        //generate bishiop moves
                        if(piece == b){
                               cbitboard = bitboards[b];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = get_bishop_attacks(source_square, occupancies[both]) & (~occupancies[black]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[white], targeted_square)){
                                                       //cout<<"bishop captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"bishop move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }
                        //generate rook moves
                         if(piece == r){
                               cbitboard = bitboards[r];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = get_rook_attacks(source_square, occupancies[both]) & (~occupancies[black]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[white], targeted_square)){
                                                       //cout<<"rook captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"rook move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        }
                        // generate queen moves
                        if(piece == q){
                               cbitboard = bitboards[q];

                               while(cbitboard){
                                       source_square = get_ls1b_index(cbitboard);
                                       attacks = get_queen_attacks(source_square, occupancies[both]) & (~occupancies[black]); 
                                       while(attacks){
                                               targeted_square = get_ls1b_index(attacks);
                                               if(getBit(occupancies[white], targeted_square)){
                                                       //cout<<"queen captures :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = (((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               else {
                                                       //cout<<"queen move :"<<coordinate[source_square]<<coordinate[targeted_square]<<'\n';
                                                       moves.moves[sz++] = ((1 << 19) | ((move | source_square) << 11) | ((move | targeted_square) << 3));
                                               }
                                               popBit(attacks, targeted_square);
                                       } 
                                       popBit(cbitboard, source_square);
                               } 
                        } 

                }



        }




        moves.size = sz;

}

void print_position(){


        for(int rank = 0; rank < 8; ++rank){
                cout<<(8 - rank)<<"  ";
                for(int file = 0; file < 8; ++file){

                        int square = 8 * rank + file;
                        int flag = 1;

                        for(int piece = 0; piece < 12 ; ++piece){
                            if(getBit(bitboards[piece], square)){
                                    cout<<pieces[piece]<<' ';
                                    flag = 0;
                                    break;
                            }    

                        }

                        if(flag){
                                cout<<'.'<<' ';
                        }

                }

                cout<<'\n';
        }

        cout<<'\n';

        cout<<"   a b c d e f g h\n";
}

static inline int is_square_attacked(int square, int side){
        if(side == white && (pawn_attacks[black][square] & bitboards[P])) return 1;

        if(side == black && (pawn_attacks[white][square] & bitboards[p])) return 1;

        if(side == white && (knight_attacks[square] & bitboards[N])) return 1;

        if(side == black && (knight_attacks[square] & bitboards[n])) return 1;

        if(side == white && (king_attacks[square] & bitboards[K])) return 1;

        if(side == black && (king_attacks[square] & bitboards[k])) return 1;

        if(side == white && (get_bishop_attacks(square, occupancies[both]) & bitboards[B])) return 1;

        if(side == black && (get_bishop_attacks(square, occupancies[both]) & bitboards[b])) return 1;

        if(side == white && (get_rook_attacks(square, occupancies[both]) & bitboards[R])) return 1;

        if(side == black && (get_rook_attacks(square, occupancies[both]) & bitboards[r])) return 1;

        if(side == white && (get_queen_attacks(square, occupancies[both]) & bitboards[Q])) return 1;

        if(side == black && (get_queen_attacks(square, occupancies[both]) & bitboards[q])) return 1;          

        return 0;
}

void print_attacked_squares(int side){

        for(int i = 0; i < 8; ++i){
                cout<<(8 - i)<<"  ";
                for(int j = 0; j < 8; ++j){
                        int square = 8 * i + j;

                       if(is_square_attacked(square, side)){
                               cout<<1<<' ';
                       } 
                       else{
                               cout<<0<<' ';
                       }

                }
                cout<<'\n';
        }
        cout<<'\n';

        cout<<"   a b c d e f g h\n";
}
