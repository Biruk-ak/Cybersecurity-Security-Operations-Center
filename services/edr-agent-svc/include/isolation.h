#ifndef SOC_EDR_AGENT_SVC_ISOLATION_H
#define SOC_EDR_AGENT_SVC_ISOLATION_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ISOLATION_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_isolation_rec_t;

typedef struct { soc_isolation_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_isolation_db_t;

soc_isolation_db_t *soc_isolation_db_create(size_t n);
void soc_isolation_db_destroy(soc_isolation_db_t *db);
int soc_isolation_db_upsert(soc_isolation_db_t *db, const soc_isolation_rec_t *rec);
int soc_isolation_db_remove(soc_isolation_db_t *db, uint64_t id);
int soc_isolation_db_find(const soc_isolation_db_t *db, uint64_t id, soc_isolation_rec_t *out);
size_t soc_isolation_db_scan(const soc_isolation_db_t *db, uint32_t min_sev, soc_isolation_rec_t *out, size_t max);
uint64_t soc_isolation_hash(const void *p, size_t n);
int soc_isolation_validate(const soc_isolation_rec_t *rec);
int soc_isolation_to_json(const soc_isolation_rec_t *rec, char *buf, size_t len);
void soc_isolation_metrics(const soc_isolation_db_t *db, char *buf, size_t len);
int soc_isolation_correlate(soc_isolation_db_t *db, const soc_isolation_rec_t *seed, soc_isolation_rec_t *out, size_t max);
int soc_isolation_fn_000(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_001(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_002(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_003(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_004(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_005(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_006(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_007(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_008(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_009(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_010(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_011(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_012(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_013(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_014(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_015(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_016(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_017(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_018(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_019(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_020(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_021(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_022(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_023(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_024(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_025(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_026(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_027(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_028(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_029(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_030(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_031(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_032(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_033(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_034(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_035(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_036(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_037(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_038(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_039(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_040(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_041(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_042(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_043(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_044(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_045(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_046(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_047(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_048(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_049(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_050(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_051(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_052(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_053(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_054(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_055(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_056(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_057(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_058(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_059(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_060(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_061(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_062(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_063(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_064(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_065(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_066(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_067(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_068(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_069(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_070(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_isolation_fn_071(soc_isolation_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_EDR_AGENT_SVC_ISOLATION_H */
