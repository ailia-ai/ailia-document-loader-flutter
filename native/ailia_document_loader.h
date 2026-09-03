/**
 * \~japanese
 * @file ailia_document_loader.h
 * @brief ailia Document Loader ライブラリ
 * @copyright AXELL CORPORATION, ax Inc.
 * @date 2023/12/05
 *
 * \~english
 * @file ailia_document_loader.h
 * @brief ailia Document Loader library
 * @copyright AXELL CORPORATION, ax Inc.
 * @date 2023/12/05
 */

#ifndef AILIA_DOCUMENT_LOADER_H
#define AILIA_DOCUMENT_LOADER_H

/* エラーコードと構造体 */

#include <wchar.h>
/* 呼び出し規約 */

#if defined(_WIN64) || defined(_M_X64) || defined(__amd64__) || defined(__x86_64__) || defined(__APPLE__) ||           \
    defined(__ANDROID__) || defined(ANDROID) || defined(__linux__) || defined(NN_NINTENDO_SDK)
#define AILIA_API
#else
#define AILIA_API __stdcall
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************
 * ライブラリ状態定義
 **/

/**
 * \~japanese
 * @def AILIA_DOCUMENT_LOADER_STATUS_SUCCESS
 * @brief 成功
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_SUCCESS
 * @brief Successful
 */
#define AILIA_DOCUMENT_LOADER_STATUS_SUCCESS (0)
/**
 * \~japanese
 * @def AILIA_DOCUMENT_LOADER_STATUS_INVALID_ARGUMENT
 * @brief 引数が不正
 * @remark API呼び出し時の引数を確認してください。
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_INVALID_ARGUMENT
 * @brief Incorrect argument
 * @remark Please check argument of called API.
 */
#define AILIA_DOCUMENT_LOADER_STATUS_INVALID_ARGUMENT (-1)

/**
 * \~japanese
 * @def AILIA_DOCUMENT_LOADER_STATUS_MEMORY_INSUFFICIENT
 * @brief メモリが不足している
 * @remark メインメモリやVRAMの空き容量を確保してからAPIを呼び出してください。
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_MEMORY_INSUFFICIENT
 * @brief Insufficient memory
 * @remark Please check usage of main memory and VRAM. And please call API after free memory.
 */
#define AILIA_DOCUMENT_LOADER_STATUS_MEMORY_INSUFFICIENT (-5)

/**
 * \~japanese
 * @def AILIADOCUMENT_LOADER__STATUS_UNIMPLEMENTED
 * @brief 未実装
 * @remark
 * 指定した環境では未実装な機能が呼び出されました。エラー内容をドキュメント記載のサポート窓口までお問い合わせください。
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_UNIMPLEMENTED
 * @brief Unimplemented error
 * @remark The called API are not available on current environment. Please contact support desk that described on
 * document.
 */
#define AILIA_DOCUMENT_LOADER_STATUS_UNIMPLEMENTED (-15)
/**
 * \~japanese
 * @def AILIA_DOCUMENT_LOADER_STATUS_UNSUPPORT_ENCRYPTED_FILE
 * @brief 暗号化されたファイルを読み込もうとしていることを示す
 * @remark
 * 暗号化されたファイルの読み込みはサポートされていません。
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_UNSUPPORT_ENCRYPTED_FILE
 * @brief Encrypted file is tried to load.
 * @remark Encrypted file loading file is not supported.
 */
#define AILIA_DOCUMENT_LOADER_STATUS_UNSUPPORT_ENCRYPTED_FILE (-24)
/**
 * \~japanese
 * @def AILIA_DOCUMENT_LOADER_STATUS_UNSUPPORTED_FILTER
 * @brief 定義されていないカラースペースを使用しようとしていることを示す
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_UNSUPPORTED_FILTER
 * @brief Unsupported base color space in /Indexed color space
 */
#define AILIA_DOCUMENT_LOADER_STATUS_UNSUPPORTED_FILTER (-25)
/**
 * \~japanese
 * @def AILIA_DOCUMENT_LOADER_STATUS_OTHER_ERROR
 * @brief 不明なエラー
 * @remark その他のエラーが発生しました。ailiaGetErrorDetail()
 * で詳細なエラーメッセージを確認し、エラー内容をドキュメント記載のサポート窓口までお問い合わせください。
 *
 * \~english
 * @def AILIA_DOCUMENT_LOADER_STATUS_OTHER_ERROR
 * @brief Unknown error
 * @remark The misc error has been occured. Please call ailiaGetErrorDetail() and check detail message. And, please
 * contact support desk that described on document.
 */
#define AILIA_DOCUMENT_LOADER_STATUS_OTHER_ERROR (-128)

    /****************************************************************
     * ドキュメントローダーオブジェクトのインスタンス
     **/

    struct AILIADocumentLoader;

    /****************************************************************
     * Document Loader API
     **/

    /**
     * \~japanese
     * @brief ドキュメントローダーオブジェクトを作成します。
     * @param loader ドキュメントローダーオブジェクトポインタへのポインタ
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ドキュメントローダーオブジェクトを作成します。
     *
     * \~english
     * @brief Creates a document loader instance.
     * @param loader A pointer to the document loader instance pointer
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Creates a document loader instance.
     */
    int AILIA_API ailiaDocumentLoaderCreate(struct AILIADocumentLoader **loader);

    /**
     * \~japanese
     * @brief PDFファイルを読み込みます。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param path PDFファイルのパス
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   PDFファイルを読み込みます。
     *
     * \~english
     * @brief PDF file.
     * @param loader A pointer to the document loader instance pointer
     * @param path PDF Path
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Open a PDF file.
     */
    int AILIA_API ailiaDocumentLoaderOpenFileA(struct AILIADocumentLoader *loader, const char *path);
    int AILIA_API ailiaDocumentLoaderOpenFileW(struct AILIADocumentLoader *loader, const wchar_t *path);

    /**
     * \~japanese
     * @brief ページ数を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param count  ページ数
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *  ページ数を取得します。
     *
     * \~english
     * @brief Get the number of pages.
     * @param loader  A document loader instance pointer
     * @param count  number of pages.
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the number of pages.
     */
    int AILIA_API ailiaDocumentLoaderGetPageCount(struct AILIADocumentLoader *loader, unsigned int *count);

    /**
     * \~japanese
     * @brief テキストの長さを取得します。(NULL文字含む)
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param size  テキストの長さ
     * @param i 指定ページ
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     *
     * \~english
     * @brief Gets the size of text. (Include null)
     * @param loader  A document loader instance pointer
     * @param size  The length of text
     * @param i  page
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     */
    int AILIA_API ailiaDocumentLoaderGetPageTextSize(struct AILIADocumentLoader *loader, unsigned int *size,
                                                     unsigned AILIA_API int i);

    /**
     * \~japanese
     * @def AILIA_DOCUMENT_LOADER_GRAPHICS_TYPE_PATH
     * @brief 描画されたパス (表の罫線、図の枠など)
     *
     * \~english
     * @def AILIA_DOCUMENT_LOADER_GRAPHICS_TYPE_PATH
     * @brief A painted path, as the rules of a table or the frame of a figure
     */
#define AILIA_DOCUMENT_LOADER_GRAPHICS_TYPE_PATH (0)
    /**
     * \~japanese
     * @def AILIA_DOCUMENT_LOADER_GRAPHICS_TYPE_IMAGE
     * @brief 画像の配置
     *
     * \~english
     * @def AILIA_DOCUMENT_LOADER_GRAPHICS_TYPE_IMAGE
     * @brief The placement of an image
     */
#define AILIA_DOCUMENT_LOADER_GRAPHICS_TYPE_IMAGE (1)

    /**
     * \~japanese
     * @def AILIA_DOCUMENT_LOADER_COLOR_SPACE_NONE
     * @brief 色が不明 (Separation / Pattern など、変換していない色空間)
     *
     * \~english
     * @def AILIA_DOCUMENT_LOADER_COLOR_SPACE_NONE
     * @brief The color is unknown, as a Separation or a Pattern one
     */
#define AILIA_DOCUMENT_LOADER_COLOR_SPACE_NONE (0)
#define AILIA_DOCUMENT_LOADER_COLOR_SPACE_GRAY (1)
#define AILIA_DOCUMENT_LOADER_COLOR_SPACE_RGB (2)
#define AILIA_DOCUMENT_LOADER_COLOR_SPACE_CMYK (3)

    /**
     * \~japanese
     * @brief 図形情報
     * @details
     *   座標系は \ref ailiaDocumentLoaderGetText の textMatrix[4], textMatrix[5] と同一です。
     *   すなわち CTM を適用したページ座標で、原点はページの左下、ページの /Rotate は
     *   適用済みです。Form XObject 内の図形は、配置ごとの CTM を適用して返します。
     *   x, y, width, height はクリッピング後の可視領域のバウンディングボックスで、
     *   clipX, clipY, clipWidth, clipHeight は適用されているクリップ矩形です
     *   (クリップが無い場合はページ全体)。
     *   x1, y1, x2, y2 は、線分の場合はクリップ前の両端点、それ以外の場合は
     *   バウンディングボックスの左下と右上の座標です。
     *   fillColorSpace と strokeColorSpace は
     *   \ref AILIA_DOCUMENT_LOADER_COLOR_SPACE_NONE などの値で、成分数は
     *   Gray が 1、RGB が 3、CMYK が 4 です。ICCBased は成分数が同じデバイス色空間として
     *   返し、Separation / Indexed / Pattern は NONE になります。
     *
     * \~english
     * @brief Graphics information
     * @details
     *   The coordinates are the ones of ailiaDocumentLoaderGetText textMatrix[4] and
     *   textMatrix[5]: the CTM is applied, hence the drawings of a form XObject are
     *   reported with the matrix of every placement applied, the origin is the lower left
     *   corner of the page and the /Rotate of the page is applied.
     *   x, y, width and height are the visible bounding box, that is the bounding box
     *   intersected with the clipping path, and clipX, clipY, clipWidth and clipHeight are
     *   the clipping rectangle in use, which is the whole page when there is none.
     *   x1, y1, x2 and y2 are the endpoints of the segment before clipping when the
     *   drawing is a line, and the corners of the bounding box otherwise.
     *   fillColorSpace and strokeColorSpace hold one of the
     *   AILIA_DOCUMENT_LOADER_COLOR_SPACE_ values: Gray has one component, RGB three and
     *   CMYK four. An ICCBased color space is reported as the device one with the same
     *   number of components, a Separation, an Indexed and a Pattern one as NONE.
     */
    struct AILIADocumentLoaderGraphicsInfo
    {
        unsigned int type;
        double x;
        double y;
        double width;
        double height;
        double x1;
        double y1;
        double x2;
        double y2;
        double clipX;
        double clipY;
        double clipWidth;
        double clipHeight;
        /// 線分の場合は 1
        unsigned int isLine;
        /// 軸に平行な矩形の場合は 1
        unsigned int isRectangle;
        unsigned int stroked;
        unsigned int filled;
        double lineWidth;
        unsigned int fillColorSpace;
        double fillColor[4];
        unsigned int strokeColorSpace;
        double strokeColor[4];
        /// 画像のオブジェクト番号 (パスの場合は 0)
        unsigned int imageObject;
    };

    /**
     * \~japanese
     * @brief ページの図形を抽出します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ページに描画されたパス (表の罫線、図の枠など) と画像の配置を抽出します。
     *   抽出結果は \ref ailiaDocumentLoaderGetPageGraphicsCount と
     *   \ref ailiaDocumentLoaderGetGraphics で取得します。
     *   パスはサブパス単位で報告するため、1 つのパスに複数の罫線が含まれていても
     *   個別に取得できます。塗りも線描画も行われないパス (クリッピングのみのパスなど) と、
     *   クリッピングにより完全に隠れるパスは含まれません。
     *   図形の順序はコンテンツストリーム上の描画順です (背景の塗りが先、その上の罫線が後)。
     *   minSize を指定すると、可視バウンディングボックスが縦横ともに minSize 未満の
     *   図形を除外します。散布図などパスが数万件になるページで有効です。
     *
     * \~english
     * @brief Extract the drawings of the page.
     * @param loader  A document loader instance pointer
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Extracts the paths painted on the page, as the rules of a table and the frame of a
     *   figure, and the placement of the images. The result is read with
     *   \ref ailiaDocumentLoaderGetPageGraphicsCount and \ref ailiaDocumentLoaderGetGraphics .
     *   The paths are reported one subpath at a time, so the rules drawn by a single path
     *   are reported separately. The paths that are neither stroked nor filled and the ones
     *   the clipping path hides entirely are not reported. The drawings are reported in the
     *   order the content stream paints them. minSize drops the drawings whose visible
     *   bounding box is smaller than it in both directions, which is useful on the pages
     *   whose plots are made of tens of thousands of paths.
     */
    int AILIA_API ailiaDocumentLoaderExtractPageGraphics(struct AILIADocumentLoader *loader, unsigned int pageIndex,
                                                         double minSize);

    /**
     * \~japanese
     * @brief 図形の数を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param count  図形の数
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   あらかじめ \ref ailiaDocumentLoaderExtractPageGraphics を呼び出しておく必要があります。
     *
     * \~english
     * @brief Get the number of the drawings.
     * @param loader  A document loader instance pointer
     * @param count  The number of the drawings
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   \ref ailiaDocumentLoaderExtractPageGraphics must have been called beforehand.
     */
    int AILIA_API ailiaDocumentLoaderGetPageGraphicsCount(struct AILIADocumentLoader *loader, unsigned int *count,
                                                          unsigned int pageIndex);

    /**
     * \~japanese
     * @brief 図形を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param graphicsInfo  図形情報オブジェクトポインタ
     * @param graphicsIndex  図形番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   あらかじめ \ref ailiaDocumentLoaderExtractPageGraphics を呼び出しておく必要があります。
     *
     * \~english
     * @brief Get a drawing.
     * @param loader  A document loader instance pointer
     * @param graphicsInfo  A graphics information instance pointer
     * @param graphicsIndex  drawing number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   \ref ailiaDocumentLoaderExtractPageGraphics must have been called beforehand.
     */
    int AILIA_API ailiaDocumentLoaderGetGraphics(struct AILIADocumentLoader *loader,
                                                 struct AILIADocumentLoaderGraphicsInfo *graphicsInfo,
                                                 unsigned int graphicsIndex);

    /**
     * \~japanese
     * @brief 図形をまとめて取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param graphicsInfo  図形情報の配列
     * @param graphicsCount  取得する図形の数
     * @param graphicsIndex  取得を開始する図形番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   graphicsIndex から graphicsCount 件の図形を配列にまとめて取得します。
     *   1 件ずつ取得すると呼び出し回数が問題になる場合に使用します。
     *
     * \~english
     * @brief Get several drawings at once.
     * @param loader  A document loader instance pointer
     * @param graphicsInfo  An array of graphics information
     * @param graphicsCount  The number of the drawings to read
     * @param graphicsIndex  The number of the first drawing to read
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Reads graphicsCount drawings starting from graphicsIndex into an array, for the
     *   callers that can't afford one call per drawing.
     */
    int AILIA_API ailiaDocumentLoaderGetGraphicsArray(struct AILIADocumentLoader *loader,
                                                      struct AILIADocumentLoaderGraphicsInfo *graphicsInfo,
                                                      unsigned int graphicsCount, unsigned int graphicsIndex);

    /**
     * \~japanese
     * @brief ページの寸法を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param width  ページの幅
     * @param height  ページの高さ
     * @param rotate  ページの回転角 (度、0 / 90 / 180 / 270)
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ページの寸法を取得します。幅と高さは回転を適用した後の値で、
     *   テキストや図形の座標と同じ座標系です。rotate には /Rotate の値を返します。
     *   width, height, rotate には NULL を指定できます。
     *
     * \~english
     * @brief Get the size of a page.
     * @param loader  A document loader instance pointer
     * @param width  The width of the page
     * @param height  The height of the page
     * @param rotate  The rotation of the page in degrees, 0, 90, 180 or 270
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   The width and the height are the ones of the rotated page, in the coordinate system
     *   of the text and of the drawings. rotate receives the value of /Rotate. width, height
     *   and rotate can be NULL.
     */
    int AILIA_API ailiaDocumentLoaderGetPageSize(struct AILIADocumentLoader *loader, double *width, double *height,
                                                 unsigned int *rotate, unsigned int pageIndex);

    /**
     * \~japanese
     * @brief テキストを取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param text  テキスト
     * @param size  テキストの長さ
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   テキストを取得します。
     *
     * \~english
     * @brief Gets the text.
     * @param loader  A document loader instance pointer
     * @param text  Text
     * @param size  The length of text
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get text.
     */
    int AILIA_API ailiaDocumentLoaderGetPageText(struct AILIADocumentLoader *loader, char *text, unsigned int size);

    struct AILIADocumentLoaderTextInfo
    {
        const char *text;
        double textMatrix[6];
        double fontSize;
        double fontScale;
        double textWidth;
        double lineSpacing;
    };

    /**
     * \~japanese
     * @brief ページのテキストを抽出します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ページのテキストを抽出します。
     *
     * \~english
     * @brief Extract text from the page.
     * @param loader  A document loader instance pointer
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Extract text from the page.
     */
    int AILIA_API ailiaDocumentLoaderExtractPageText(struct AILIADocumentLoader *loader, unsigned int pageIndex);

    /**
     * \~japanese
     * @brief テキストの数を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param count テキストの数
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ページに含まれるテキストブロックの数を取得します。
     *
     * \~english
     * @brief Get the number of text.
     * @param loader  A document loader instance pointer
     * @param count  The number of text
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the number of text blocks on the page.
     */
    int AILIA_API ailiaDocumentLoaderGetPageTextCount(struct AILIADocumentLoader *loader, unsigned int *count,
                                                      unsigned int pageIndex);

    /**
     * \~japanese
     * @brief 元のテキストを削除します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ページに含まれる元のテキストを削除します。
     *
     * \~english
     * @brief Remove the original text.
     * @param loader  A document loader instance pointer
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Remove the original text on the page.
     */
    int AILIA_API ailiaDocumentLoaderRemoveOriginalText(struct AILIADocumentLoader *loader, unsigned int pageIndex);

    /**
     * \~japanese
     * @brief 指定したテキストのみを削除します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param pageIndex  ページ番号
     * @param textIndices  削除するテキスト番号の配列
     * @param textIndexCount  textIndices の要素数
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   textIndices で指定したテキストのみを PDF から削除します。
     *   テキスト番号は \ref ailiaDocumentLoaderExtractPageText で抽出した順序であり、
     *   あらかじめ同じページに対して \ref ailiaDocumentLoaderExtractPageText を
     *   呼び出しておく必要があります。
     *
     * \~english
     * @brief Remove only the specified text.
     * @param loader  A document loader instance pointer
     * @param pageIndex  page number
     * @param textIndices  An array of the text numbers to remove
     * @param textIndexCount  The number of the elements of textIndices
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Removes only the text specified by textIndices from the PDF. The text numbers are the ones of the
     *   extraction performed by \ref ailiaDocumentLoaderExtractPageText , which must have been called for
     *   the same page beforehand.
     */
    int AILIA_API ailiaDocumentLoaderRemoveOriginalTextByIndex(struct AILIADocumentLoader *loader,
                                                               unsigned int pageIndex, const unsigned int *textIndices,
                                                               unsigned int textIndexCount);

    /**
     * \~japanese
     * @brief テキストを取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param textInfo  テキスト情報オブジェクトポインタ
     * @param textIndex  テキスト番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   テキストを取得します。
     *
     * \~english
     * @brief Get the text.
     * @param loader  A document loader instance pointer
     * @param textInfo  A text Info instance pointer
     * @param textIndex  text number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the text.
     */
    int AILIA_API ailiaDocumentLoaderGetText(struct AILIADocumentLoader *loader,
                                             struct AILIADocumentLoaderTextInfo *textInfo, unsigned int textIndex);

    /**
     * \~japanese
     * @brief テキストを設定します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param text テキスト
     * @param pageIndex  ページ番号
     * @param textIndex  テキスト番号
     * @param fontFilePath  フォントファイルパス (TrueTyep と OpenType のフォントのみサポート)
     * @param fontSize  フォントサイズ
     * @param fontScale  フォントスケール
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   テキストを設定します。
     *
     * \~english
     * @brief Set the text.
     * @param loader  A document loader instance pointer
     * @param text Text
     * @param pageIndex  page number
     * @param textInfo  A text Info instance pointer
     * @param fontFilePath  font file path (only TrueType and OpenType fonts are supported)
     * @param fontSize  font size
     * @param fontScale  font scale
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Set the text.
     */
    int AILIA_API ailiaDocumentLoaderSetTextA(struct AILIADocumentLoader *loader, const char *text,
                                              unsigned int pageIndex, unsigned int textIndex, const char *fontFilePath,
                                              double fontSize, double fontScale);
    int AILIA_API ailiaDocumentLoaderSetTextW(struct AILIADocumentLoader *loader, const char *text,
                                              unsigned int pageIndex, unsigned int textIndex,
                                              const wchar_t *fontFilePath, double fontSize, double fontScale);

    /**
     * \~japanese
     * @brief テキストの幅を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param width  テキストの幅
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   テキストの幅を取得します。
     *
     * \~english
     * @brief Get the text width.
     * @param loader  A document loader instance pointer
     * @param width  The width of text
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the text width.
     */
    int AILIA_API ailiaDocumentLoaderGetTextWidth(struct AILIADocumentLoader *loader, double *width);

    /**
     * \~japanese
     * @brief テキストを描画します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   テキストを描画します。
     *
     * \~english
     * @brief Draw the text.
     * @param loader  A document loader instance pointer
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Draw the text.
     */
    int AILIA_API ailiaDocumentLoaderDrawText(struct AILIADocumentLoader *loader);

    /**
     * \~japanese
     * @brief ドキュメントを書き込みます。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param outputFilePath 出力ファイルパス
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   ドキュメントを書き込みます。
     *
     * \~english
     * @brief Write the document.
     * @param loader  A document loader instance pointer
     * @param outputFilePath  Output file path
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Write the document.
     */
    int AILIA_API ailiaDocumentLoaderWriteDocumentA(struct AILIADocumentLoader *loader, const char *outputFilePath);
    int AILIA_API ailiaDocumentLoaderWriteDocumentW(struct AILIADocumentLoader *loader, const wchar_t *outputFilePath);

    /**
     * \~japanese
     * @brief 画像フォーマット
     *
     * \~english
     * @brief Image format
     */
    enum AiliaImageFormat
    {
        None,
        Jpeg,
        Jpeg2000
    };

    /**
     * \~japanese
     * @brief 画像の数を取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param count  画像の数
     * @param pageIndex  ページ番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   画像の数を取得します。
     *
     * \~english
     * @brief Get the number of images.
     * @param loader  A document loader instance pointer
     * @param count  The number of images
     * @param pageIndex  page number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the number of images.
     */
    int AILIA_API ailiaDocumentLoaderGetImageCount(struct AILIADocumentLoader *loader, unsigned int *count,
                                                   unsigned int pageIndex);

    /**
     * \~japanese
     * @brief 画像のフォーマットを取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param format  画像のフォーマット
     * @param pageIndex  ページ番号
     * @param imageIndex  画像番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   画像のフォーマットを取得します。
     *
     * \~english
     * @brief Get the image format.
     * @param loader  A document loader instance pointer
     * @param format  The image format
     * @param pageIndex  page number
     * @param imageIndex  image number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the image format.
     */
    int AILIA_API ailiaDocumentLoaderGetImageFormat(struct AILIADocumentLoader *loader, enum AiliaImageFormat *format,
                                                    unsigned int pageIndex, unsigned int imageIndex);

    /**
     * \~japanese
     * @brief 画像のバッファサイズを取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param bufferSize  画像のバッファサイズ
     * @param pageIndex  ページ番号
     * @param imageIndex  画像番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   画像のバッファサイズを取得します。
     *
     * \~english
     * @brief Get the image buffer size.
     * @param loader  A document loader instance pointer
     * @param bufferSize  The image buffer size
     * @param pageIndex  page number
     * @param imageIndex  image number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the image buffer size.
     */
    int AILIA_API ailiaDocumentLoaderGetImageBufferSize(struct AILIADocumentLoader *loader, unsigned int *bufferSize,
                                                        unsigned int pageIndex, unsigned int imageIndex);

    /**
     * \~japanese
     * @brief 画像のバッファを取得します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     * @param buffer  画像のバッファ
     * @param bufferSize  画像のバッファサイズ
     * @param pageIndex  ページ番号
     * @param imageIndex  画像番号
     * @return
     *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
     * @details
     *   画像のバッファを取得します。
     *
     * \~english
     * @brief Get the image buffer.
     * @param loader  A document loader instance pointer
     * @param buffer  The image buffer
     * @param bufferSize  The image buffer size
     * @param pageIndex  page number
     * @param imageIndex  image number
     * @return
     *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
     * @details
     *   Get the image buffer.
     */
    int AILIA_API ailiaDocumentLoaderGetImageBuffer(struct AILIADocumentLoader *loader, char *buffer,
                                                    unsigned int bufferSize, unsigned int pageIndex,
                                                    unsigned int imageIndex);

    /**
     * \~japanese
     * @brief ドキュメントローダーオブジェクトを破棄します。
     * @param loader ドキュメントローダーオブジェクトポインタ
     *
     * \~english
     * @brief It destroys the document loader instance.
     * @param loader A document loader instance pointer
     */
    void AILIA_API ailiaDocumentLoaderDestroy(struct AILIADocumentLoader *loader);

#ifdef __cplusplus
}
#endif
#endif // AILIA_DOCUMENT_LOADER_H
