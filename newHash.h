#ifndef NEWHASH_H
#define NEWHASH_H

#define NEWHASH_DIGEST_SIZE ( 256 / 8)
#define NEWHASH_BLOCK_SIZE  ( 512 / 8)

#define SHFR(x, n)    (x >> n)
#define ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define CH(x, y, z)  ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

#define NEWHASH_F1(x) (ROTR(x,  2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define NEWHASH_F2(x) (ROTR(x,  6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define NEWHASH_F3(x) (ROTR(x,  7) ^ ROTR(x, 18) ^ SHFR(x,  3))
#define NEWHASH_F4(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHFR(x, 10))

typedef struct {
    unsigned int tot_len;
    unsigned int len;
    unsigned char block[2 * NEWHASH_BLOCK_SIZE];
    unsigned int h[8];
} NEWHASH_ctx;

extern unsigned int NEWHASH_k[64];

void NEWHASH_init(NEWHASH_ctx * ctx);
void NEWHASH_update(NEWHASH_ctx *ctx, const unsigned char *message,
                   unsigned int len);
void NEWHASH_final(NEWHASH_ctx *ctx, unsigned char *digest);
void NEWHASH(const unsigned char *message, unsigned int len,
            unsigned char *digest);

#endif /* !NEWHASH_H */
