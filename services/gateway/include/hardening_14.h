#ifndef SOC_GATEWAY_HARDENING_14_H
#define SOC_GATEWAY_HARDENING_14_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_HARDENING_14_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_hardening_14_rec_t;

typedef struct { soc_hardening_14_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_hardening_14_db_t;

soc_hardening_14_db_t *soc_hardening_14_db_create(size_t n);
void soc_hardening_14_db_destroy(soc_hardening_14_db_t *db);
int soc_hardening_14_db_upsert(soc_hardening_14_db_t *db, const soc_hardening_14_rec_t *rec);
int soc_hardening_14_db_remove(soc_hardening_14_db_t *db, uint64_t id);
int soc_hardening_14_db_find(const soc_hardening_14_db_t *db, uint64_t id, soc_hardening_14_rec_t *out);
size_t soc_hardening_14_db_scan(const soc_hardening_14_db_t *db, uint32_t min_sev, soc_hardening_14_rec_t *out, size_t max);
uint64_t soc_hardening_14_hash(const void *p, size_t n);
int soc_hardening_14_validate(const soc_hardening_14_rec_t *rec);
int soc_hardening_14_to_json(const soc_hardening_14_rec_t *rec, char *buf, size_t len);
void soc_hardening_14_metrics(const soc_hardening_14_db_t *db, char *buf, size_t len);
int soc_hardening_14_correlate(soc_hardening_14_db_t *db, const soc_hardening_14_rec_t *seed, soc_hardening_14_rec_t *out, size_t max);
int soc_hardening_14_fn_000(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_001(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_002(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_003(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_004(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_005(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_006(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_007(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_008(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_009(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_010(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_011(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_012(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_013(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_014(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_015(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_016(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_017(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_018(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_019(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_020(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_021(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_022(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_023(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_024(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_025(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_026(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_027(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_028(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_029(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_030(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_031(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_032(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_033(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_034(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_035(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_036(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_037(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_038(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_039(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_040(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_041(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_042(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_043(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_044(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_045(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_046(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_047(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_048(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_hardening_14_fn_049(soc_hardening_14_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_HARDENING_14_H */
