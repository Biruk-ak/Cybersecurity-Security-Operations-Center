#ifndef SOC_EDR_AGENT_SVC_MEMORY_H
#define SOC_EDR_AGENT_SVC_MEMORY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_MEMORY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_memory_rec_t;

typedef struct { soc_memory_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_memory_db_t;

soc_memory_db_t *soc_memory_db_create(size_t n);
void soc_memory_db_destroy(soc_memory_db_t *db);
int soc_memory_db_upsert(soc_memory_db_t *db, const soc_memory_rec_t *rec);
int soc_memory_db_remove(soc_memory_db_t *db, uint64_t id);
int soc_memory_db_find(const soc_memory_db_t *db, uint64_t id, soc_memory_rec_t *out);
size_t soc_memory_db_scan(const soc_memory_db_t *db, uint32_t min_sev, soc_memory_rec_t *out, size_t max);
uint64_t soc_memory_hash(const void *p, size_t n);
int soc_memory_validate(const soc_memory_rec_t *rec);
int soc_memory_to_json(const soc_memory_rec_t *rec, char *buf, size_t len);
void soc_memory_metrics(const soc_memory_db_t *db, char *buf, size_t len);
int soc_memory_correlate(soc_memory_db_t *db, const soc_memory_rec_t *seed, soc_memory_rec_t *out, size_t max);
int soc_memory_fn_000(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_001(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_002(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_003(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_004(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_005(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_006(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_007(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_008(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_009(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_010(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_011(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_012(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_013(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_014(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_015(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_016(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_017(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_018(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_019(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_020(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_021(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_022(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_023(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_024(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_025(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_026(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_027(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_028(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_029(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_030(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_031(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_032(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_033(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_034(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_035(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_036(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_037(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_038(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_039(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_040(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_041(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_042(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_043(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_044(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_045(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_046(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_047(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_048(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_049(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_050(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_051(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_052(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_053(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_054(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_055(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_056(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_057(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_058(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_059(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_060(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_061(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_062(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_063(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_064(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_065(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_066(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_067(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_068(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_069(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_070(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_memory_fn_071(soc_memory_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_EDR_AGENT_SVC_MEMORY_H */
