#pragma once

#include <QCommonStyle>

class CustomIconStyle : public QCommonStyle
{
	Q_OBJECT

public:
	CustomIconStyle();
	~CustomIconStyle();

	virtual int pixelMetric(PixelMetric m, const QStyleOption *opt = Q_NULLPTR, const QWidget *widget = Q_NULLPTR) const;
	void setIconSize(int nSize);
private:
	int mSize;
};
