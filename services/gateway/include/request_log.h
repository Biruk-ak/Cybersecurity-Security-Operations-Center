#ifndef SOC_GATEWAY_REQUEST_LOG_H
#define SOC_GATEWAY_REQUEST_LOG_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_REQUEST_LOG_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_request_log_rec_t;

typedef struct { soc_request_log_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_request_log_db_t;

soc_request_log_db_t *soc_request_log_db_create(size_t n);
void soc_request_log_db_destroy(soc_request_log_db_t *db);
int soc_request_log_db_upsert(soc_request_log_db_t *db, const soc_request_log_rec_t *rec);
int soc_request_log_db_remove(soc_request_log_db_t *db, uint64_t id);
int soc_request_log_db_find(const soc_request_log_db_t *db, uint64_t id, soc_request_log_rec_t *out);
size_t soc_request_log_db_scan(const soc_request_log_db_t *db, uint32_t min_sev, soc_request_log_rec_t *out, size_t max);
uint64_t soc_request_log_hash(const void *p, size_t n);
int soc_request_log_validate(const soc_request_log_rec_t *rec);
int soc_request_log_to_json(const soc_request_log_rec_t *rec, char *buf, size_t len);
void soc_request_log_metrics(const soc_request_log_db_t *db, char *buf, size_t len);
int soc_request_log_correlate(soc_request_log_db_t *db, const soc_request_log_rec_t *seed, soc_request_log_rec_t *out, size_t max);
int soc_request_log_fn_000(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_001(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_002(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_003(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_004(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_005(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_006(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_007(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_008(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_009(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_010(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_011(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_012(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_013(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_014(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_015(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_016(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_017(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_018(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_019(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_020(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_021(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_022(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_023(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_024(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_025(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_026(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_027(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_028(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_029(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_030(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_031(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_032(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_033(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_034(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_035(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_036(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_037(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_038(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_039(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_040(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_041(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_042(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_043(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_044(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_045(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_046(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_047(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_048(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_049(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_050(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_051(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_052(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_053(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_054(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_055(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_056(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_057(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_058(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_059(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_060(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_061(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_062(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_063(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_request_log_fn_064(soc_request_log_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_REQUEST_LOG_H */
