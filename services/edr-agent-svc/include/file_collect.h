#ifndef SOC_EDR_AGENT_SVC_FILE_COLLECT_H
#define SOC_EDR_AGENT_SVC_FILE_COLLECT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_FILE_COLLECT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_file_collect_rec_t;

typedef struct { soc_file_collect_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_file_collect_db_t;

soc_file_collect_db_t *soc_file_collect_db_create(size_t n);
void soc_file_collect_db_destroy(soc_file_collect_db_t *db);
int soc_file_collect_db_upsert(soc_file_collect_db_t *db, const soc_file_collect_rec_t *rec);
int soc_file_collect_db_remove(soc_file_collect_db_t *db, uint64_t id);
int soc_file_collect_db_find(const soc_file_collect_db_t *db, uint64_t id, soc_file_collect_rec_t *out);
size_t soc_file_collect_db_scan(const soc_file_collect_db_t *db, uint32_t min_sev, soc_file_collect_rec_t *out, size_t max);
uint64_t soc_file_collect_hash(const void *p, size_t n);
int soc_file_collect_validate(const soc_file_collect_rec_t *rec);
int soc_file_collect_to_json(const soc_file_collect_rec_t *rec, char *buf, size_t len);
void soc_file_collect_metrics(const soc_file_collect_db_t *db, char *buf, size_t len);
int soc_file_collect_correlate(soc_file_collect_db_t *db, const soc_file_collect_rec_t *seed, soc_file_collect_rec_t *out, size_t max);
int soc_file_collect_fn_000(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_001(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_002(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_003(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_004(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_005(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_006(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_007(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_008(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_009(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_010(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_011(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_012(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_013(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_014(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_015(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_016(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_017(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_018(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_019(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_020(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_021(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_022(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_023(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_024(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_025(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_026(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_027(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_028(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_029(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_030(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_031(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_032(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_033(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_034(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_035(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_036(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_037(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_038(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_039(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_040(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_041(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_042(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_043(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_044(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_045(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_046(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_047(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_048(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_049(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_050(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_051(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_052(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_053(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_054(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_055(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_056(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_057(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_058(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_059(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_060(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_061(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_062(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_063(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_064(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_065(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_066(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_067(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_068(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_069(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_070(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_file_collect_fn_071(soc_file_collect_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_EDR_AGENT_SVC_FILE_COLLECT_H */
