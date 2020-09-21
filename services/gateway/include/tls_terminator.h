#ifndef SOC_GATEWAY_TLS_TERMINATOR_H
#define SOC_GATEWAY_TLS_TERMINATOR_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_TLS_TERMINATOR_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_tls_terminator_rec_t;

typedef struct { soc_tls_terminator_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_tls_terminator_db_t;

soc_tls_terminator_db_t *soc_tls_terminator_db_create(size_t n);
void soc_tls_terminator_db_destroy(soc_tls_terminator_db_t *db);
int soc_tls_terminator_db_upsert(soc_tls_terminator_db_t *db, const soc_tls_terminator_rec_t *rec);
int soc_tls_terminator_db_remove(soc_tls_terminator_db_t *db, uint64_t id);
int soc_tls_terminator_db_find(const soc_tls_terminator_db_t *db, uint64_t id, soc_tls_terminator_rec_t *out);
size_t soc_tls_terminator_db_scan(const soc_tls_terminator_db_t *db, uint32_t min_sev, soc_tls_terminator_rec_t *out, size_t max);
uint64_t soc_tls_terminator_hash(const void *p, size_t n);
int soc_tls_terminator_validate(const soc_tls_terminator_rec_t *rec);
int soc_tls_terminator_to_json(const soc_tls_terminator_rec_t *rec, char *buf, size_t len);
void soc_tls_terminator_metrics(const soc_tls_terminator_db_t *db, char *buf, size_t len);
int soc_tls_terminator_correlate(soc_tls_terminator_db_t *db, const soc_tls_terminator_rec_t *seed, soc_tls_terminator_rec_t *out, size_t max);
int soc_tls_terminator_fn_000(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_001(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_002(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_003(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_004(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_005(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_006(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_007(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_008(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_009(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_010(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_011(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_012(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_013(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_014(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_015(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_016(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_017(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_018(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_019(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_020(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_021(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_022(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_023(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_024(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_025(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_026(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_027(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_028(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_029(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_030(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_031(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_032(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_033(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_034(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_035(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_036(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_037(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_038(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_039(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_040(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_041(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_042(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_043(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_044(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_045(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_046(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_047(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_048(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_049(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_050(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_051(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_052(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_053(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_054(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_055(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_056(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_057(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_058(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_059(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_060(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_061(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_062(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_063(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_tls_terminator_fn_064(soc_tls_terminator_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_TLS_TERMINATOR_H */
