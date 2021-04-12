#ifndef SOC_EDR_AGENT_SVC_PROCESS_H
#define SOC_EDR_AGENT_SVC_PROCESS_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PROCESS_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_process_rec_t;

typedef struct { soc_process_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_process_db_t;

soc_process_db_t *soc_process_db_create(size_t n);
void soc_process_db_destroy(soc_process_db_t *db);
int soc_process_db_upsert(soc_process_db_t *db, const soc_process_rec_t *rec);
int soc_process_db_remove(soc_process_db_t *db, uint64_t id);
int soc_process_db_find(const soc_process_db_t *db, uint64_t id, soc_process_rec_t *out);
size_t soc_process_db_scan(const soc_process_db_t *db, uint32_t min_sev, soc_process_rec_t *out, size_t max);
uint64_t soc_process_hash(const void *p, size_t n);
int soc_process_validate(const soc_process_rec_t *rec);
int soc_process_to_json(const soc_process_rec_t *rec, char *buf, size_t len);
void soc_process_metrics(const soc_process_db_t *db, char *buf, size_t len);
int soc_process_correlate(soc_process_db_t *db, const soc_process_rec_t *seed, soc_process_rec_t *out, size_t max);
int soc_process_fn_000(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_001(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_002(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_003(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_004(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_005(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_006(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_007(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_008(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_009(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_010(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_011(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_012(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_013(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_014(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_015(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_016(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_017(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_018(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_019(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_020(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_021(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_022(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_023(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_024(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_025(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_026(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_027(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_028(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_029(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_030(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_031(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_032(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_033(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_034(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_035(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_036(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_037(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_038(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_039(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_040(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_041(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_042(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_043(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_044(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_045(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_046(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_047(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_048(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_049(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_050(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_051(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_052(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_053(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_054(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_055(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_056(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_057(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_058(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_059(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_060(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_061(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_062(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_063(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_064(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_065(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_066(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_067(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_068(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_069(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_070(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_process_fn_071(soc_process_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_EDR_AGENT_SVC_PROCESS_H */
