#include <jni.h>
#include <string>
#include "libyuv.h"

// nv21 --> i420
void nv21ToI420(jbyte *src_nv21_data, jint width, jint height, jbyte *dst_i420_data) {
    jint src_y_size = width * height;
    jbyte *src_nv21_y_data = src_nv21_data;
    jbyte *src_nv21_vu_data = src_nv21_data + src_y_size;

    jint dst_y_size = width * height;
    jint dst_u_size = (width >> 1) * (height >> 1);
    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + dst_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + dst_y_size + dst_u_size;

    libyuv::NV21ToI420((const uint8 *) src_nv21_y_data, width,
                       (const uint8 *) src_nv21_vu_data, width,
                       (uint8 *) dst_i420_y_data, width,
                       (uint8 *) dst_i420_u_data, width >> 1,
                       (uint8 *) dst_i420_v_data, width >> 1,
                       width, height);
}

// i420 --> nv21
void i420ToNv21(jbyte *src_i420_data, jint width, jint height, jbyte *dst_nv21_data) {
    jint dst_y_size = width * height;
    jbyte *dst_nv21_y_data = dst_nv21_data;
    jbyte *dst_nv21_uv_data = dst_nv21_data + dst_y_size;

    jint src_y_size = width * height;
    jint src_u_size = (width >> 1) * (height >> 1);
    jbyte *src_i420_y_data = src_i420_data;
    jbyte *src_i420_u_data = src_i420_data + src_y_size;
    jbyte *src_i420_v_data = src_i420_data + src_y_size + src_u_size;

    libyuv::I420ToNV21(
            (const uint8 *) src_i420_y_data, width,
            (const uint8 *) src_i420_u_data, width >> 1,
            (const uint8 *) src_i420_v_data, width >> 1,
            (uint8 *) dst_nv21_y_data, width,
            (uint8 *) dst_nv21_uv_data, width,
            width, height);
}

// nv12 --> i420
void nv12ToI420(jbyte *src_nv12_data, jint width, jint height, jbyte *dst_i420_data) {
    jint src_y_size = width * height;
    jbyte *src_nv12_y_data = src_nv12_data;
    jbyte *src_nv12_uv_data = src_nv12_data + src_y_size;

    jint dst_y_size = width * height;
    jint dst_u_size = (width >> 1) * (height >> 1);
    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + dst_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + dst_y_size + dst_u_size;

    libyuv::NV12ToI420((const uint8 *) src_nv12_y_data, width,
                       (const uint8 *) src_nv12_uv_data, width,
                       (uint8 *) dst_i420_y_data, width,
                       (uint8 *) dst_i420_u_data, width >> 1,
                       (uint8 *) dst_i420_v_data, width >> 1,
                       width, height);
}

// i420 --> nv12
void i420ToNv12(jbyte *src_i420_data, jint width, jint height, jbyte *dst_nv12_data) {
    jint dst_y_size = width * height;

    jbyte *dst_nv12_y_data = dst_nv12_data;
    jbyte *dst_nv12_uv_data = dst_nv12_data + dst_y_size;

    jint src_y_size = width * height;
    jint src_u_size = (width >> 1) * (height >> 1);
    jbyte *src_i420_y_data = src_i420_data;
    jbyte *src_i420_u_data = src_i420_data + src_y_size;
    jbyte *src_i420_v_data = src_i420_data + src_y_size + src_u_size;

    libyuv::I420ToNV12(
            (const uint8 *) src_i420_y_data, width,
            (const uint8 *) src_i420_u_data, width >> 1,
            (const uint8 *) src_i420_v_data, width >> 1,
            (uint8 *) dst_nv12_y_data, width,
            (uint8 *) dst_nv12_uv_data, width,
            width, height);
}

// 镜像I420
void mirrorI420(jbyte *src_i420_data, jint width, jint height, jbyte *dst_i420_data) {
    jint src_i420_y_size = width * height;
    jint src_i420_u_size = (width >> 1) * (height >> 1);
    jbyte *src_i420_y_data = src_i420_data;
    jbyte *src_i420_u_data = src_i420_data + src_i420_y_size;
    jbyte *src_i420_v_data = src_i420_data + src_i420_y_size + src_i420_u_size;

    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + src_i420_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + src_i420_y_size + src_i420_u_size;

    libyuv::I420Mirror((const uint8 *) src_i420_y_data, width,
                       (const uint8 *) src_i420_u_data, width >> 1,
                       (const uint8 *) src_i420_v_data, width >> 1,
                       (uint8 *) dst_i420_y_data, width,
                       (uint8 *) dst_i420_u_data, width >> 1,
                       (uint8 *) dst_i420_v_data, width >> 1,
                       width, height);
}

// 旋转I420
void rotateI420(jbyte *src_i420_data, jint width, jint height, jbyte *dst_i420_data, jint degree) {
    jint src_i420_y_size = width * height;
    jint src_i420_u_size = (width >> 1) * (height >> 1);

    jbyte *src_i420_y_data = src_i420_data;
    jbyte *src_i420_u_data = src_i420_data + src_i420_y_size;
    jbyte *src_i420_v_data = src_i420_data + src_i420_y_size + src_i420_u_size;

    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + src_i420_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + src_i420_y_size + src_i420_u_size;

    //要注意这里的width和height在旋转之后是相反的
    if (degree == libyuv::kRotate90 || degree == libyuv::kRotate270) {
        libyuv::I420Rotate((const uint8 *) src_i420_y_data, width,
                           (const uint8 *) src_i420_u_data, width >> 1,
                           (const uint8 *) src_i420_v_data, width >> 1,
                           (uint8 *) dst_i420_y_data, height,
                           (uint8 *) dst_i420_u_data, height >> 1,
                           (uint8 *) dst_i420_v_data, height >> 1,
                           width, height,
                           (libyuv::RotationMode) degree);
    } else {
        libyuv::I420Rotate((const uint8 *) src_i420_y_data, width,
                           (const uint8 *) src_i420_u_data, width >> 1,
                           (const uint8 *) src_i420_v_data, width >> 1,
                           (uint8 *) dst_i420_y_data, width,
                           (uint8 *) dst_i420_u_data, width >> 1,
                           (uint8 *) dst_i420_v_data, width >> 1,
                           width, height,
                           (libyuv::RotationMode) degree);
    }
}

// 缩放I420
void scaleI420(jbyte *src_i420_data, jint width, jint height, jbyte *dst_i420_data, jint dst_width,
               jint dst_height, jint mode) {

    jint src_i420_y_size = width * height;
    jint src_i420_u_size = (width >> 1) * (height >> 1);
    jbyte *src_i420_y_data = src_i420_data;
    jbyte *src_i420_u_data = src_i420_data + src_i420_y_size;
    jbyte *src_i420_v_data = src_i420_data + src_i420_y_size + src_i420_u_size;

    jint dst_i420_y_size = dst_width * dst_height;
    jint dst_i420_u_size = (dst_width >> 1) * (dst_height >> 1);
    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + dst_i420_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + dst_i420_y_size + dst_i420_u_size;

    libyuv::I420Scale((const uint8 *) src_i420_y_data, width,
                      (const uint8 *) src_i420_u_data, width >> 1,
                      (const uint8 *) src_i420_v_data, width >> 1,
                      width, height,
                      (uint8 *) dst_i420_y_data, dst_width,
                      (uint8 *) dst_i420_u_data, dst_width >> 1,
                      (uint8 *) dst_i420_v_data, dst_width >> 1,
                      dst_width, dst_height,
                      (libyuv::FilterMode) mode);
}

// 裁剪I420
void cropI420(jbyte *src_i420_data, jint src_length, jint width, jint height,
              jbyte *dst_i420_data, jint dst_width, jint dst_height, jint left, jint top) {

    jint dst_i420_y_size = dst_width * dst_height;
    jint dst_i420_u_size = (dst_width >> 1) * (dst_height >> 1);

    jbyte *dst_i420_y_data = dst_i420_data;
    jbyte *dst_i420_u_data = dst_i420_data + dst_i420_y_size;
    jbyte *dst_i420_v_data = dst_i420_data + dst_i420_y_size + dst_i420_u_size;

    libyuv::ConvertToI420((const uint8 *) src_i420_data, static_cast<size_t>(src_length),
                          (uint8 *) dst_i420_y_data, dst_width,
                          (uint8 *) dst_i420_u_data, dst_width >> 1,
                          (uint8 *) dst_i420_v_data, dst_width >> 1,
                          left, top,
                          width, height,
                          dst_width, dst_height,
                          libyuv::kRotate0, libyuv::FOURCC_I420);
}